#ifndef TRANSLATORENGINE_H
#define TRANSLATORENGINE_H

#include <QString>
#include <QObject>
class TranslatorEngine:public QObject
{
    Q_OBJECT
public:
    TranslatorEngine(QObject *parent=nullptr);
public slots:
    virtual void  translateWord(QString wordToTranslate)=0;
signals:
     void translationFinished(QString translatedWord);
};

#endif // TRANSLATORENGINE_H
