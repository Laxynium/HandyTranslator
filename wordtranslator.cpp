#include "wordtranslator.h"
#include <QString>
#include <bab_latranslatorengine.h>
#include <QDebug>
WordTranslator::WordTranslator(QObject *parent):QObject(parent)
{

}

void WordTranslator::translateWord(QString wordToTranslate)
{
    wordToTranslate.remove('.');
    wordToTranslate.remove(',');
    wordToTranslate.remove(':');
    wordToTranslate=wordToTranslate.simplified();
    m_Engin->translateWord(wordToTranslate);
    connect(m_Engin,&TranslatorEngine::translationFinished,[this](QString translated)
    {
        emit translationFinished(translated);
    });
}

void WordTranslator::setEngine(TranslatorEngine&engin)
{
    m_Engin=&engin;
}
