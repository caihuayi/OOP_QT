#ifndef TABLE_H
#define TABLE_H
#include <QString>
#include <iostream>
#include <vector>

class Table
{
private:
    typedef struct{
        QString name;
        int num;
    }Person;
    std::vector<Person> list;
public:
    Table();		//	构造函数
    ~Table();		//	析构函数
    void Add(QString name, int num); //  添加
    int Sum();		//	求总和
    int Lookup(QString name);		//  查找
    void Output(std::ostream &out);	//  输出
};

#endif // TABLE_H
