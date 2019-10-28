#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QPen>
#include <QBrush>
#include <iostream>
#include <QList>
#include <QString>
#include <QKeyEvent>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QString>
#include "linefactory.h"
#include "circlefactory.h"
#include "rectanglefactory.h"
#include "trianglefactory.h"

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
    void keyPressEvent(QKeyEvent*);
    ~MainWindow();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_btn_save_clicked();

    void on_btn_load_clicked();

private:
    const std::string path8 = "~/Desktop/dgaadsqwergfgfsasd.txt";
    Graph* createObj();
    Graph* whichActive();
    bool isInList(Graph*);
    QList<Graph*>::iterator getGraphIter(Graph*);

    enum GraphType{_circle, _rectangle, _triangle, _line};
    Ui::MainWindow *ui;
    //Graph *cir;
    QPen pen;
    QBrush brush;
    QList<Graph*> list;
    GraphType type;
    GraphFactory *factory;
};
#endif // MAINWINDOW_H
