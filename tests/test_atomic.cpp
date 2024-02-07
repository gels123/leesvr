//
// Created by gels on 2024/1/23.
//
#include<iostream>
#include "stdio.h"
#include <thread>

//static int num = 0;
std::atomic<int> num;

void f() {
    for(int i=1;i<=200;++i) {
        ++num; // 原子递增或递减
    }
}
int main() {
    num.store(0); // 设置值
    num.exchange(0); // 替换值
    int old1 = num.fetch_add(0); // 加
    int old2 = num.fetch_sub(0); // 减
    int x = 0;
    num.compare_exchange_weak(x, 1); // 比较并设置
    std::thread th1(f);
    std::thread th2(f);
    std::thread th3(f);
    th1.join();
    th2.join();
    th3.join();
    std::cout << num.load() << std::endl; // 读取值
    return 0;
}