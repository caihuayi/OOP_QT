#include "license.h"

License::License()
{

}

License::License(long no, QString name, QString type,
                 QDate date, int expery)
{
    this->no = no;
    this->name = name;
    this->type = type;
    this->date = date;
    this->expery = expery;
    expery_date = date.addYears(expery);
}

void License::set_type(QString type)
{
    this->type = type;
}
