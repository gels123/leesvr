/*
    1. 插入元素：下标方式访问map[key] vs insert方式
        下标方式, 实际上通过重载运算符[]来实现，它直接进行插入或覆盖，如果key不存在，则会插入一个默认值value, 并返回value，产生未知效果。
        insert()会先判断如果存在则返回，否则插入。尽量使用insert。
    2. 获取元素: 下标方式value=map[key] or 迭代器方式value=it->second
    3. 元素删除auto it_next = map.erase(it)
        参数it必须是有效迭代器，不能是结束迭代器，否者崩溃，c++11返回下一个迭代器或结束迭代器。
    4. 线程安全的问题, 2个线程同时修改map元素, 需要加锁

    编译：
        g++ -o c4.exe c4.cpp -std=c++11
*/
#include <stdio.h>
#include <iostream>
#include <map>

int main(int argv, char **argc)
{
    std::map<int, int> map;
    map.insert(std::make_pair(1, 100));
    map.insert(std::make_pair(2, 200));
    printf("==1==size=%d\n", map.size());
    // 以下一行, 下标方式查询, 将产生未知错误
    printf("==2==%d size=%d\n", map[3], map.size());
    printf("==3==产生非法元素map[3]=%d\n", map.find(3)->second);


    std::map<int, int> map2;
    std::map<int, int>::iterator it1 = map2.begin();
    auto it2 = map2.end();
    printf("=====it1=%p it2=%p\n", it1, it2);
    // 一下2行, 迭代器指向的是一块结束的地址, 对其释放会导致进程卡主
    // map2.erase(it1);
    // map2.erase(it2);

    std::map<int, int> map3;
    auto it3 = map3.begin(); //这行不正确, 此时迭代器指向结束地址
    map3.insert(std::make_pair(1, 1000));
    map3.insert(std::make_pair(2, 2000));
    for (; it3 != map3.end(); ++it3)
    {
        printf("====test333===key=%d value=%d\n", it3->first, it3->second);
    }

    printf("main end=\n");

    return 0;
}