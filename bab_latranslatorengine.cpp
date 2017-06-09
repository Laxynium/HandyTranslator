#include "bab_latranslatorengine.h"
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QThread>
#include <string>
#include <iostream>
bab_laTranslatorengine::bab_laTranslatorengine(QObject *parent):TranslatorEngine(parent)
{
    manager.reset(new QNetworkAccessManager);
    connect(manager.get(),&QNetworkAccessManager::finished,
            [this](QNetworkReply*reply)
    {
        if(!reply->error())
        {
            QByteArray arr=reply->readAll();
            downloadedHtml=arr;
            translationFinished(findTranslatedWords());
        }else
        {
             translationFinished("Network connection not found");
        }
        reply->deleteLater();
    });
}

void bab_laTranslatorengine::translateWord(QString wordToTranslate)
{
    downloadHtml(createUrl(wordToTranslate));
}

QString bab_laTranslatorengine::createUrl(QString wordToTranslate)
{
    static const QString base_of_Url="http://pl.bab.la/slownik/angielski-polski/";
    return  base_of_Url+wordToTranslate;
}

void bab_laTranslatorengine::downloadHtml(QString url)
{
    manager->get(QNetworkRequest(QUrl(url)));
}

QString bab_laTranslatorengine::findTranslatedWords()
{
    QString words="";
    QString wholehtml=downloadedHtml;
    const QString pattern="<ul class='sense-group-results'>";
    const QString endOfListTag="</ul>";
    int begin=0;
    int end=0;
    while(begin!=-1)
    {
         begin=wholehtml.indexOf(pattern,end+endOfListTag.length()+1);
         end=wholehtml.indexOf(endOfListTag,begin);
         auto html=wholehtml.mid(begin,end-begin+1+endOfListTag.length());
         words+=getWordsFromList(html);
    }
    if(words.isEmpty())return tr("Translation not found\n");

    return words;
}

QString bab_laTranslatorengine::getWordsFromList(QString html)
{
    QString words="";
    const QString endOfTag="</a>";
    int index2=0;
    while(index2!=-1)
    {

        index2=html.indexOf(endOfTag,index2+endOfTag.length());//plus
        if(index2==-1)break;
        auto inx=index2;
        while(inx>=0&&html[inx]!='>')
            inx--;
        words+=html.mid(inx+1,index2-inx-1)+';';
    }
    return words;
}
