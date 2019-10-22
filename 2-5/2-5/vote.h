#ifndef VOTE_H
#define VOTE_H
#include <QVector>
#include "person.h"

class Vote
{
private:
    QVector<Person*> list;
    double standary;
    int count;
public:
    Vote();
    ~Vote();
    Vote(QVector<Person*>& v);
    QVector<Person*>& get_list();
    int get_count();
    int get_standary();
    bool set_standary(double s);
    bool add_person(QString &name);
    bool vote_to(QString name, int count);
};

#endif // VOTE_H
