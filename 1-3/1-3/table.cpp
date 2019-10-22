#include "Table.h"
using namespace std;
Table::Table()
{

}

Table::~Table()
{

}

void Table::Add(QString name, int num)
{
    for (auto &iter : list)
    {
        if (name == iter.name)
        {
            iter.num += num;
            return;
        }
    }
    Person *p = new Person();
    p->name = name;
    p->num = num;
    list.push_back(*p);
}

int Table::Sum()
{
    int sum = 0;
    for (auto it : list)
    {
        sum += it.num;
    }

    return sum;
}

int Table::Lookup(QString name)
{
    for (auto it : list)
    {
        if(it.name == name)
        {
            return it.num;
        }
    }
    return -1;
}

void Table::Output(std::ostream &out)
{
    for (auto it : list)
    {
        out << it.name.toStdString()<< "\t" << it.num << endl;
    }
}
