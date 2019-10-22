#include "delegate.h"

Delegate::Delegate()
{

}

Goods& Delegate::search_goods(QString name)
{
    static Goods dummy;
    for (auto& iter : list)
    {
        if (iter.name == name)
        {
            return iter;
        }
    }

    return dummy;
}


bool Delegate::add_goods(Goods goods)
{
    for (auto it : list)
    {
        if (it.name == goods.name)
            return false;
    }
    list.push_back(Goods(goods));
    return true;
}

bool Delegate::bidding(QString goods_name, int num)
{
    if (another_bidding(goods_name) == true)
    {
        return false;
    }
    Goods *goods = &search_goods(goods_name);
    goods->is_bidding = true;
    if (goods->final >= num)
    {
        return false;
    }
    else
    {
        goods->final = num;
    }

    return true;
}

bool Delegate::another_bidding(QString name)
{
    for (auto it : list)
    {
        if (it.is_bidding == true && it.name != name)
        {
            return true;
        }
    }
    return false;
}

bool Delegate::knockdown(QString goods_name)
{
    Goods *goods = &search_goods(goods_name);
    goods->is_bidding = false;
    if (goods->final >= goods->reserve_price)
    {
        goods->is_knockdown = true;
    }
    else
    {
        goods->is_knockdown = false;
    }

    return goods->is_knockdown;
}

QStringList Delegate::get_list()
{
    QStringList qslist;
    for (auto &it : list)
    {
        qslist.append(it.name);
    }

    return qslist;
}

