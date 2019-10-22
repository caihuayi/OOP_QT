#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QString>
#include <QPen>
#include <QBrush>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent* pe);
    void mouseMoveEvent(QMouseEvent*);

private:
    Ui::MainWindow *ui;
    QRect rect;
    QPen pen;
    QLine line;
    QBrush brush;
    float zoom;

};
#endif // MAINWINDOW_H
