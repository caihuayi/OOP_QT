#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QApplication::connect(ui->pushButton, SIGNAL(click()), ui->label, SLOT(textChange()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::textChange()
{

}


void MainWindow::on_pushButton_clicked()
{
      ui->label->setText("hello qt");
}
