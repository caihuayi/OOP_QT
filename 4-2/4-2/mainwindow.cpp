#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    QStringList stringList = {"circle", "rectangle", "triangle", "line"};
    ui->comboBox->addItems(stringList);
    type = _circle;
    cir = new Rectangle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    cir->Draw(painter);
}

void MainWindow::mousePressEvent(QMouseEvent *mouse)
{
    bool is_active = false;
    for (auto& iter : list)
    {
        is_active = iter->get_active();
    }
    if (is_active == false)
    {
        if (cir->get_exist() == true)
        {
            cir->OnPress(mouse->x(), mouse->y());
            cir->old_x = mouse->x();
            cir->old_y = mouse->y();
        }
        else
        {
            cir->begPoint(mouse->x(), mouse->y());
        }
    }
    else
    {

    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *mouse)
{
    if (mouse->buttons() & Qt::LeftButton)
    {
        if (cir->get_exist() == false)
        {
            cir->Create(mouse->x(), mouse->y());
            if (mouse->buttons() & Qt::LeftButton)
            {
                cir->Create(mouse->x(), mouse->y());
                this->update();
            }
        }
        else
        {
            if (cir->get_active() == true)
            {
                cir->OnPress(mouse->x(), mouse->y());
                cir->OnMove(mouse->x()-cir->old_x, mouse->y()-cir->old_y);
                this->update();
                cir->OnRelease(mouse->x(), mouse->y());
            }
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *mouse)
{
    cir->OnRelease(mouse->x(), mouse->y());
    cir->set_active(false);
    cout << "active == false" << endl;
}




void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if (arg1 == "circle")
    {
        type = _circle;
    }
    else if (arg1 == "rectangle")
    {
        type = _rectangle;
    }
    else if (arg1 == "triangle")
    {
        type = _triangle;
    }
    else if (arg1 == "line")
    {
        type = _line;
    }
}
