#include "licensemanage.h"
using namespace std;
LicenseManage::LicenseManage()
{

}

LicenseManage::~LicenseManage()
{
    for (auto &it : items)
    {
        delete it;
    }
    items.clear();
}

int LicenseManage::regist(License* plic)
{
    this->items.push_back(plic);
    return items.size() - 1;
}

License* LicenseManage::lookup(long no)
{
    for (auto it : items)
    {
        if (it->no == no)
        {
            return it;
        }
    }

    return nullptr;
}

int LicenseManage::cancel(long no)
{
    int n = -1;
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i]->no == no)
        {
            License* lic = items[i];
            items.erase(items.cbegin()+i);
            delete lic;
            n = i;
        }
    }

    return n;
}

QString& LicenseManage::getName(long no)
{
    return lookup(no)->name;
}

QString& LicenseManage::getType(long no)
{
    return lookup(no)->type;
}

void LicenseManage::setType(long no, QString Type)
{
    lookup(no)->set_type(Type);
}

QDate& LicenseManage::getExperyDate(long no)
{
    return lookup(no)->expery_date;
}

int LicenseManage::extendExpery(long no, int ex)
{
    License *ls = lookup(no);
    ls->expery += ex;
    ls->expery_date = ls->date.addYears(ls->expery);
    return ls->expery;
}

int LicenseManage::getExpery(long no)
{
    return lookup(no)->expery;
}
