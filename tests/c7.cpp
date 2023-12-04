#include <stdio.h>
#include <string.h>
#include <iostream>

class Base
{
public:
    Base();
    virtual ~Base();
};

Base::Base()
{
    printf("===Base::Base===\n");
}

Base::~Base()
{
    printf("===Base::~Base===\n");
}

class Son : public Base
{
public:
    Son();
    ~Son();
};on::Son()
{
    printf("===Son::Son===\n");
}

Son::~Son()
{
    printf("===Son::~Son===\n");
}

int main(int argv, char **argc)
{
    Base *p = new Son(); //子类在构造时, 会自动调用基类的构造函数
    delete p;
    // 输出如下, 并没有调用子类的析构函数
    // ===Base::Base===
    // ===Son::Son===
    // ===Base::~Base===

    //umdh
    return true;
}