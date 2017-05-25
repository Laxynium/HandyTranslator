#ifndef BAB_LATRANSLATORENGINE_H
#define BAB_LATRANSLATORENGINE_H

#include <translatorengine.h>
#include <QNetworkAccessManager>
#include <memory>
class babLatranslatorengine:public TranslatorEngine
{
    Q_OBJECT
public:
    babLatranslatorengine(QObject *parent=nullptr);
public slots:
    virtual void  translateWord(QString wordToTranslate)override;
private:
    QString createUrl(QString wordToTranslate);
    void  downloadHtml(QString url);
    QString findTranslatedWords();
    QString getWordsFromList(QString html);
private:
    QString downloadedHtml;
    std::unique_ptr<QNetworkAccessManager>manager;


};

#endif // BAB_LATRANSLATORENGINE_H
