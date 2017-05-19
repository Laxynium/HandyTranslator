#ifndef CLIPBOARDTRANSLATOR_H
#define CLIPBOARDTRANSLATOR_H

#include <QMainWindow>
class WordTranslator;
namespace Ui {
class ClipBoardTranslator;
}

class ClipBoardTranslator : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClipBoardTranslator(QWidget *parent = 0);
    ~ClipBoardTranslator();
private slots:
    void onClipBoardChange();
private:
    Ui::ClipBoardTranslator *ui;
    WordTranslator *translator=nullptr;
};

#endif // CLIPBOARDTRANSLATOR_H
