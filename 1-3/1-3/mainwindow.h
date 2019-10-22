#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Table.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Table tab;

private slots:
    void on_btn_submit_clicked();

    void on_btn_search_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
