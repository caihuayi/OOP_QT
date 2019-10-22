#ifndef LICENSE_H
#define LICENSE_H
#include <QString>
#include <QDate>
class License
{
private:
    long no;
    QString type;
    QString name;
    QDate date;
    int expery;
    QDate expery_date;
public:
    License();
    License(long no, QString name, QString type, QDate date, int expery);
    void set_type(QString type);
    friend class LicenseManage;
};

#endif // LICENSE_H
