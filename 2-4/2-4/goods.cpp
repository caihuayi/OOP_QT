#include "goods.h"

Goods::Goods()
{
   final = 0;
   is_bidding = false;
   is_knockdown = false;
}

Goods::Goods(QString delegater_name, QString name, int reserve_price) : Goods()
{
    this->delegater_name = delegater_name;
    this->name = name;
    this->reserve_price = reserve_price;
}

int Goods::get_final()
{
    return this->final;
}
