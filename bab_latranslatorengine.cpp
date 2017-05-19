#include "bab_latranslatorengine.h"
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QThread>
#include <string>
#include <iostream>
babLatranslatorengine::babLatranslatorengine(QObject *parent):TranslatorEngine(parent)
{
    manager.reset(new QNetworkAccessManager);
    connect(manager.get(),&QNetworkAccessManager::finished,
            [this](QNetworkReply*reply)
    {
        QByteArray arr=reply->readAll();
        downloadedHtml=arr;
        reply->deleteLater();
        emit downloadFinished();

    });
    connect(this,&babLatranslatorengine::downloadFinished,[this]()
    {
        emit translationFinished(findTranslatedWords());
    });
}

void babLatranslatorengine::translateWord(QString wordToTranslate)
{
    downloadHtml(createUrl(wordToTranslate));

}

QString babLatranslatorengine::createUrl(QString wordToTranslate)
{
    static const QString base_of_Url="http://pl.bab.la/slownik/angielski-polski/";
    return  base_of_Url+wordToTranslate;
}

void babLatranslatorengine::downloadHtml(QString url)
{
    manager->get(QNetworkRequest(QUrl(url)));
}

QString babLatranslatorengine::findTranslatedWord()
{
    auto index=downloadedHtml.indexOf("<ul class='sense-group-results'>");
    if(index==-1)return tr("Translation not found\n");
    auto subStr=downloadedHtml.mid(index,120);
    auto index2=subStr.indexOf("</a>");
    if(index2==-1)return tr("Translation not found\n");
    auto inx=index2;
    while(inx>=0&&subStr[inx]!='>')
        inx--;
    return subStr.mid(inx+1,index2-inx-1);
}

QString babLatranslatorengine::findTranslatedWords()
{
    QString words="";
    QString wholehtml=downloadedHtml;
    const QString pattern="<ul class='sense-group-results'>";
    const QString endOfList="</ul>";
    int begin=0;
    int end=0;
    while(begin!=-1)
    {
         begin=wholehtml.indexOf(pattern,end+endOfList.length()+1);
         end=wholehtml.indexOf(endOfList,begin);
         auto html=wholehtml.mid(begin,end-begin+1+endOfList.length());
         words+=getWordsFromList(html);
    }

    if(words.isEmpty())return tr("Translation not found\n");

    return words;
}

QString babLatranslatorengine::getWordsFromList(QString html)
{
    QString words="";
    int index2=0;
    while(index2!=-1)
    {
        index2=html.indexOf("</a>",index2+4);
        if(index2==-1)break;
        auto inx=index2;
        while(inx>=0&&html[inx]!='>')
            inx--;
        words+=html.mid(inx+1,index2-inx-1)+';';
    }
    return words;
}
