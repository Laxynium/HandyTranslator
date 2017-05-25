#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>
#include <applicationdescription.h>
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    translator.reset(new ClipBoardTranslator());
    translator->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::Tool);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //prevent from immediate closure
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Close application",tr("Are you sure?\n"),
                                                    QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}
void MainWindow::on_pushButton_clicked()
{
    translator->show();
    translator->move(this->x()+this->width(),this->y());
}

void MainWindow::on_pushButton_2_clicked()
{
    ApplicationDescription app(this);
    app.exec();
}
