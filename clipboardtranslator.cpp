#include "clipboardtranslator.h"
#include "ui_clipboardtranslator.h"
#include <QClipboard>
#include <bab_latranslatorengine.h>
#include <wordtranslator.h>
#include <QDebug>
ClipBoardTranslator::ClipBoardTranslator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClipBoardTranslator)
{
    ui->setupUi(this);
    connect(QApplication::clipboard(),&QClipboard::dataChanged,this,&ClipBoardTranslator::onClipBoardChange);

    translator=new WordTranslator(this);
    bab_laTranslatorengine *engin=new bab_laTranslatorengine(this);
    translator->setEngine(*engin);
    connect(translator,&WordTranslator::translationFinished,
            [this](QString translated){
            //delete semicolon at end
            QString words=translated.left(translated.size()-1);
            ui->textEdit->setText(translated.replace(';',",\n"));
    });
}

ClipBoardTranslator::~ClipBoardTranslator()
{
    delete ui;
}

void ClipBoardTranslator::onClipBoardChange()
{
    auto clipBoard=QApplication::clipboard();
    auto text=clipBoard->text();
    translator->translateWord(text);
    if(this->isHidden())
        this->move( QCursor::pos());
    this->show();

}
