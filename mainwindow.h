#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <memory>
#include "clipboardtranslator.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<ClipBoardTranslator>translator=nullptr;

    // QWidget interface
protected:
    virtual void closeEvent(QCloseEvent *event) override;

private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
