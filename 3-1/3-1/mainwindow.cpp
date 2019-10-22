#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   win = new Window(50, 50, 50, 50, 350, 350);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    rect = win->toQtRect();
    line = win->toQtLine();
    //rect.setRect(200, 200, 160, 160);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete win;
}

void MainWindow::paintEvent(QPaintEvent* pe)
{
    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(rect);
    painter.drawLine(line);
}

void MainWindow::mousePressEvent(QMouseEvent* mouse)
{
    if (win != nullptr)
        win->onRelease(mouse->x(), mouse->y());
}

void MainWindow::mouseMoveEvent(QMouseEvent* mouse)
{
    if (mouse->buttons() & Qt::LeftButton)
    {
        if (win == nullptr)
        {
            win->create(mouse->x(), mouse->y());
        }
        win->onPress(mouse->x(), mouse->y());
        win->onMove(mouse->x()-win->ord_x, mouse->y()-win->ord_y);
        rect = win->toQtRect();
        line = win->toQtLine();
        this->update();
        win->onRelease(mouse->x(), mouse->y());
    }
}
