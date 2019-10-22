#ifndef PERSON_H
#define PERSON_H
#include <QString>

class Person
{
private:
    QString name;
    bool isCanditate;
    int vote_count;
public:
    Person();
    Person(QString &n);
    bool voteTo(int count);
    QString get_name();
    int get_vote();
    friend class Vote;
};

#endif // PERSON_H
