#ifndef GOODS_H
#define GOODS_H
#include <QString>

class Goods
{
private:
    QString delegater_name;
    QString name;
    int reserve_price;
    int final;
    bool is_bidding;
    bool is_knockdown;
public:
    Goods();
    Goods(QString delegater_name, QString name, int reserve_price);
    QString get_delegater_name();
    int get_final();
    bool get_is_knockdown();
    friend class Delegate;
};

#endif // GOODS_H
