#include "person.h"
using namespace std;
Person::Person()
{
}

Person::Person(QString &n)
{
    name = n;
    isCanditate = false;
    vote_count = 0;
}

bool Person::voteTo(int count)
{
    if (this->isCanditate == false)
    {
        return false;
    }
    else
    {
        vote_count += count;
        return true;
    }
}

QString Person::get_name()
{
    return name;
}

int Person::get_vote()
{
    return vote_count;
}
