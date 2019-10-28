#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QFile data("/Users/huayicai/Desktop/file8.txt");
    if (data.open(QFile::WriteOnly | QIODevice::Truncate))
    {
        QTextStream out(&data);
        out << "The answer is" << " " << 42;
    }
    data.close();

    if (data.open(QFile::ReadOnly))
    {
        QTextStream in(&data);
        QString s1, s2, s3;
        in >> s1 >> s2 >> s3;
        cout << s1.toStdString() << " " << s2.toStdString() << " " << s3.toStdString() << endl;
    }
    return a.exec();
}
