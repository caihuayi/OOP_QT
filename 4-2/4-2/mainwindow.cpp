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
    //cir = new Circle();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (list.isEmpty() == false)
    {
        for(auto &iter : list)
        {
            delete iter;
        }
    }
    list.clear();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if (list.isEmpty() == true) return;
    for (auto &iter : list)
    {
        iter->Draw(painter);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *mouse)
{
    Graph* gra;
    if (list.isEmpty() != true)
    {
        for (auto &iter : list)
        {
            iter->OnPress(mouse->x(), mouse->y());
        }
    }
    gra = whichActive();

    if (gra == nullptr)
    {
        gra = createObj();
        if (list.isEmpty() != true)
        {
            Graph *ig = list.back();
            if (ig->get_exist() == false)
            {
                list.pop_back();
                delete ig;
            }
        }
        list.push_back(gra);
        gra->begPoint(mouse->x(), mouse->y());
    }
    else
    {
        if (gra->get_exist() == true)   //准备拖动
        {
            gra->OnPress(mouse->x(), mouse->y());
            gra->old_x = mouse->x();
            gra->old_y = mouse->y();
            this->update();
        }
        else
        {

        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *mouse)
{
    if (mouse->buttons() & Qt::LeftButton)
    {
        Graph *gra = nullptr;
        for (auto &iter : list)
        {
            if (iter->isIn(mouse->x(), mouse->y()) == true)
            {
                gra = iter;
            }
        }
        if (gra == nullptr)
        {
            gra = list.back();
            //gra->Create(mouse->x(), mouse->y());
            if (mouse->buttons() & Qt::LeftButton)
            {
                if (gra->get_exist() == false)
                {
                    gra->Create(mouse->x(), mouse->y());
                    this->update();
                }
            }
        }
        else
        {
            if (gra->get_active() == true)
            {
                if (isInList(gra))
                {
                    list.push_back(gra);
                    list.erase(getGraphIter(gra));

                }
                cout << "list.size=" << list.size() << endl;

                gra->OnPress(mouse->x(), mouse->y());
                gra->OnMove(mouse->x()-gra->old_x, mouse->y()-gra->old_y);
                this->update();
                gra->OnRelease(mouse->x(), mouse->y());
            }
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *mouse)
{
    Graph *gra = list.back();
    gra->OnRelease(mouse->x(), mouse->y());
    gra->set_active(false);
    //cout << "active == false" << endl;
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

Graph* MainWindow::createObj()
{
    if (type == _circle)
    {
        factory = new CircleFactory();
    }
    else if(type == _rectangle)
    {
        factory = new RectangleFactory();
    }
    else if(type == _triangle)
    {
        factory = new TriangleFactory();
    }
    else if(type == _line)
    {
        factory = new LineFactory();
    }
    else
    {
        factory = nullptr;
    }
    Graph* gra = factory->create();
    delete factory;

    return gra;
}

Graph* MainWindow::whichActive()
{
    Graph *gra = nullptr;
    if (list.isEmpty() != true)
    {
        for (auto &iter : list)
        {
            if (iter->get_active() == true)
            {
                gra = iter;
            }
        }
    }


    return gra;
}

bool MainWindow::isInList(Graph* gra)
{
    for (auto& iter : list)
    {
        if (iter == gra)
        {
            return true;
        }
    }
    return false;
}

QList<Graph*>::iterator MainWindow::getGraphIter(Graph* gra)
{
    QList<Graph*>::iterator iter;
    for (iter = list.begin(); iter != list.end(); iter++)
    {
        if (gra == *iter)
        {
            return iter;
        }
    }
    return list.end();
}

void MainWindow::keyPressEvent(QKeyEvent *key)
{
    if (key->key() == Qt::Key_Space)
    {
        list.push_back(list.first());
        list.erase(list.begin());
        this->update();
    }
}

void MainWindow::on_btn_save_clicked()
{
    QFile data("/Users/huayicai/Desktop/file.txt");
    if (data.open(QFile::WriteOnly | QIODevice::Truncate))
    {
        QTextStream out(&data);
        out << list.size() << endl;
        for (auto &iter : list)
        {
            iter->write_file(out);
        }
        data.close();
    }
}

void MainWindow::on_btn_load_clicked()
{
    QFile data("/Users/huayicai/Desktop/file.txt");
    if (data.open(QFile::ReadOnly))
    {
        QTextStream in(&data);
        int count;
        int type;
        in >> count;
        for (int i = 0; i < count; i++)
        {
            Graph *gra;
            in >> type;
            switch(type)
            {
            case 1:
                gra = new Circle();break;
            case 2:
                gra = new Rectangle();break;
            case 3:
                gra = new Triangle();break;
            case 4:
                gra = new Line();break;
            default:
                throw "wrong type";
            }
            gra->read_file(in);
            list.push_back(gra);
        }
        data.close();
        this->update();
    }
}
