#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "circle.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPen>
#include <QBrush>
#include <iostream>
#include <vector>
#include <QList>
#include <QString>
#include "rectangle.h"
#include "triangle.h"
#include "line.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    ~MainWindow();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Graph* createObj();
    Graph* whichActive(double x, double y);

    enum GraphType{_circle, _rectangle, _triangle, _line};
    Ui::MainWindow *ui;
    //Graph *cir;
    QPen pen;
    QBrush brush;
    QList<Graph*> list;
    GraphType type;

};
#endif // MAINWINDOW_H
