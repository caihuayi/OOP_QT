#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <delegate.h>
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
    void on_btn_bidding_clicked();

    void on_btn_knockdown_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Delegate delegate;
};
#endif // MAINWINDOW_H
