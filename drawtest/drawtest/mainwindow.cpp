#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    line.setLine(200, 230, 360, 230);
    pen.setColor(Qt::blue);
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    rect.setRect(200, 200, 160, 160);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* pe)
{
    QPainter p(this);
    p.setPen(pen);
    p.setBrush(brush);
    //p.drawRect(rect);
    p.drawLine(line);
    //p.drawEllipse(20, 20, 200, 200);
    QPoint point[3] = {QPoint(20, 20), QPoint(220, 20), QPoint(120, 120)};
    p.drawPolygon(point, 3, Qt::OddEvenFill);
    p.drawEllipse(QPointF(200, 200), 200, 100);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        QPoint p;
        p.setX(event->x());
        p.setY(event->y());
        ui->label_X->setText(QString::number(event->x()));
        ui->label_Y->setText(QString::number(event->y()));
        //rect.setTopLeft(p);
        rect.moveTo(p);
        //rect.setLeft((p.x() - rect.left()));
        this->update();
    }
}
