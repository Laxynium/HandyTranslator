#ifndef BAB_LATRANSLATORENGINE_H
#define BAB_LATRANSLATORENGINE_H

#include <translatorengine.h>
#include <QNetworkAccessManager>
#include <memory>
class bab_laTranslatorengine:public TranslatorEngine
{
    Q_OBJECT
public:
    bab_laTranslatorengine(QObject *parent=nullptr);
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
