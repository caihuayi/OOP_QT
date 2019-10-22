#include "vote.h"

Vote::Vote()
{

}

Vote::Vote(QVector<Person*>& v)
{
    list = v;
    standary = 0;
}

Vote::~Vote()
{
    for (auto &iter : list)
    {
        delete iter;
    }
    list.clear();
}

QVector<Person*>& Vote::get_list()
{
    return list;
}

int Vote::get_count()
{
    return count;
}

bool Vote::set_standary(double s)
{
    if (s > 0 && s <= 1)
    {
        standary = s;
        return true;
    }
    else
    {
        return false;
    }
}

bool Vote::add_person(QString &name)
{
    for (auto iter : list)
    {
        if (iter->get_name() == name)
        {
            return false;
        }
    }
    Person *p = new Person(name);
    p->isCanditate = true;
    p->vote_count = 0;
    list.append(p);

    return true;
}

bool Vote::vote_to(QString name, int count)
{
    for(auto& iter : list)
    {
        if (iter->get_name() == name)
        {
            iter->voteTo(count);
            return true;
        }
    }
    return false;
}
