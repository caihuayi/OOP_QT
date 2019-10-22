#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Goods g1("messi", "car", 100);
    Goods g2("caihuayi", "plane", 200);
    Goods g3("Samuel", "rocket", 300);
    delegate.add_goods(g1);
    delegate.add_goods(g2);
    delegate.add_goods(g3);
    ui->comboBox->addItems(delegate.get_list());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_bidding_clicked()
{
    QString name = ui->comboBox->currentText();
    int num = ui->lineEdit_num->text().toInt();
    bool succeed = delegate.bidding(name, num);
    if (succeed == true)
    {
        ui->label->setNum(num);
    }
    ui->lineEdit_num->clear();
}

void MainWindow::on_btn_knockdown_clicked()
{
    QString name = ui->comboBox->currentText();
    bool is_knockdown = delegate.knockdown(name);
    QString str_label;
    if (is_knockdown == true)
    {
        str_label = "成交";
    }
    else
    {
        str_label = "流拍";
    }
    ui->label->setText(str_label);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->lineEdit_num->clear();
    if (delegate.another_bidding(ui->comboBox->currentText()) == true)
    {
        ui->btn_bidding->setEnabled(false);
        ui->btn_knockdown->setEnabled(false);
    }
    else
    {
        ui->btn_bidding->setEnabled(true);
        ui->btn_knockdown->setEnabled(true);
    }
    ui->label->setNum(delegate.search_goods(ui->comboBox->currentText()).get_final());
}
