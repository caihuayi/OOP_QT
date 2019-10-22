#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString name;
    char a = 'a';
    for (int i = 0; i < 12; i++)
    {
        name = "";
        name += a + i;
        list.append(name);
    }
    for (int i = 0; i < 12; i++)
    {
        ui->list1->addItem(list[i]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete vote;
    delete dv;
}


void MainWindow::on_btn_add_clicked()
{
    ui->list2->clear();
    QListWidgetItem *item = ui->list1->currentItem();
    //ui->list1->removeItemWidget()
    QString name = item->text();
    list_canditate.append(name);
    ui->list1->removeItemWidget(item);
    for (auto &iter : list_canditate)
    {
        ui->list2->addItem(iter);
    }
    delete item;
}

void MainWindow::on_btn_delete_clicked()
{
    QListWidgetItem *item = ui->list2->currentItem();
    ui->list1->addItem(item->text());
    ui->list2->removeItemWidget(item);
    for (QVector<QString>::iterator iter = list_canditate.begin(); iter != list_canditate.end(); ++iter)
    {
        cout << "0" << endl;
        if (*iter == item->text())
        {
            cout << "1" << endl;
            list_canditate.erase(iter);
            cout << "2" << endl;
        }
    }

    delete item;
}

void MainWindow::on_btn_next_clicked()
{
    dv = new DialogVote(this, list_canditate);
    dv->setModal(true);
    dv->show();
}
