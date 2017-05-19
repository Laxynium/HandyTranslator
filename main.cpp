#include "mainwindow.h"
#include <QApplication>
#include "clipboardtranslator.h"
#include <QFlag>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // ClipBoardTranslator w2;
    w.show();
   // w2.show();

    return a.exec();
}
