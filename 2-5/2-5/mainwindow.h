#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vote.h"
#include <QVector>
#include <QString>
#include <string>
#include <iostream>
#include "dialogvote.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_add_clicked();

    void on_btn_delete_clicked();

    void on_btn_next_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QString> list;
    QVector<QString> list_canditate;
    Vote *vote;
    DialogVote *dv;
};
#endif // MAINWINDOW_H
