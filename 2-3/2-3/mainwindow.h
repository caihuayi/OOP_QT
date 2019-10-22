#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "licensemanage.h"
#include <QMainWindow>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    LicenseManage lm;

private slots:
    void on_btn_register_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_expery_clicked();

    void on_pushButton_typemodify_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
