#ifndef LICENSEMANAGE_H
#define LICENSEMANAGE_H
#include <vector>
#include "license.h"
#include <iterator>
class LicenseManage
{
private:
    std::vector<License*> items;
public:
    LicenseManage();
    ~LicenseManage();
    int regist(License* plic);
    int cancel(long no);
    class License *lookup(long no);
    QString& getName(long no);	//  获得名字
    QString& getType(long no);	//  获得类型
    void setType(long no, QString Type);	//  设置类型
    QDate& getExperyDate(long no);	//  到期日
    int extendExpery(long no, int ex);		//  延长有效期
    int getExpery(long no);

};

#endif // LICENSEMANAGE_H
