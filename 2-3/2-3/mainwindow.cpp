#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_register_clicked()
{
    long no = ui->lineEdit_no->text().toLong();
    QString name = ui->lineEdit_name->text();
    QString type = ui->lineEdit_type->text();
    QDate date = ui->dateEdit->date();
    int expery = ui->lineEdit_expery->text().toInt();
    License* lic = new License(no, name, type, date, expery);
    lm.regist(lic);
    ui->lineEdit_no->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_expery->clear();
    ui->dateEdit->clear();
}

void MainWindow::on_pushButton_cancel_clicked()
{
    long no = ui->lineEdit_no->text().toLong();
    lm.cancel(no);
}

void MainWindow::on_pushButton_search_clicked()
{
    long no = ui->lineEdit_no->text().toLong();
    if (lm.lookup(no) == nullptr)
    {
        Dialog dia;
        dia.setModal(true);
        dia.exec();
        ui->lineEdit_name->clear();
        ui->lineEdit_no->clear();
        ui->lineEdit_type->clear();
        ui->lineEdit_expery->clear();
        ui->dateEdit->clear();
        return;
    }
    ui->lineEdit_name->setText(lm.getName(no));
    ui->lineEdit_type->setText(lm.getType(no));
    ui->lineEdit_expery->setText(QString::number(lm.getExpery(no)));
}

void MainWindow::on_pushButton_expery_clicked()
{
    int ex = ui->lineEdit_expery->text().toInt();
    long no = ui->lineEdit_no->text().toLong();
    lm.extendExpery(no, ex);
}

void MainWindow::on_pushButton_typemodify_clicked()
{
    long no = ui->lineEdit_no->text().toLong();
    lm.setType(no, ui->lineEdit_type->text());
}
