#include "dialogresult.h"
#include "ui_dialogresult.h"

DialogResult::DialogResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResult)
{
    ui->setupUi(this);
}

DialogResult::DialogResult(QString name, QWidget *parent):DialogResult(parent)
{
    ui->label->setText(name);
}



DialogResult::~DialogResult()
{
    delete ui;
}
