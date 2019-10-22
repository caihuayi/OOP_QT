#ifndef DELEGATE_H
#define DELEGATE_H
#include "goods.h"
#include <vector>
#include <QStringList>

class Delegate
{
private:
    std::vector<Goods> list;
public:
    Delegate();
    bool add_goods(Goods goods);
    bool bidding(QString goods_name,int num);
    bool another_bidding(QString name);
    bool knockdown(QString goods_name);
    QStringList get_list();
    Goods& search_goods(QString name);
};

#endif // DELEGATE_H
