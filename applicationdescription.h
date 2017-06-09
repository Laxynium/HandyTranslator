#ifndef APPLICATIONDESCRIPTION_H
#define APPLICATIONDESCRIPTION_H

#include <QDialog>

namespace Ui {
class ApplicationDescription;
}

class ApplicationDescription : public QDialog
{
    Q_OBJECT

public:
    explicit ApplicationDescription(QWidget *parent = 0);
    ~ApplicationDescription();

private:
    Ui::ApplicationDescription *ui=nullptr;
};

#endif // APPLICATIONDESCRIPTION_H
