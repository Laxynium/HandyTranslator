#include "applicationdescription.h"
#include "ui_applicationdescription.h"

ApplicationDescription::ApplicationDescription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ApplicationDescription)
{
    ui->setupUi(this);
}

ApplicationDescription::~ApplicationDescription()
{
    delete ui;
}
