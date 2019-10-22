#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
using namespace std;

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


void MainWindow::on_btn_submit_clicked()
{
   QString name = ui->lineEdit_name->text();
   int num = ui->lineEdit_num->text().toInt();
   tab.Add(name, num);
   ui->lineEdit_num->clear();
   ui->lineEdit_name->clear();
}

void MainWindow::on_btn_search_clicked()
{
    if (ui->checkbox_all->isChecked() == true)
    {
        ui->label->setNum(tab.Sum());
    }
    else
    {
        QString name = ui->lineEdit_name->text();
        int num = tab.Lookup(name);
        QString str_num = QString::number(num);
        ui->lineEdit_num->setText(str_num);
    }
}
