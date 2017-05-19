#ifndef WORDTRANSLATOR_H
#define WORDTRANSLATOR_H

#include <QString>
#include <QObject>
class TranslatorEngine;
class WordTranslator:public QObject
{
    Q_OBJECT
public:
    WordTranslator(QObject *parent=nullptr);
    void translateWord(QString wordToTranslate);
    virtual void setEngine(TranslatorEngine&engin);
signals:
    void translationFinished(QString translatedWord);
private:
    TranslatorEngine *m_Engin;
};

#endif // WORDTRANSLATOR_H
