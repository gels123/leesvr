//g++ -o test_ptr.out test_ptr.cpp -std=c++11
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<memory>

int main(int n, char *args[]) {
    std::shared_ptr<int> p1 = std::make_shared<int>(100);
    std::shared_ptr<int> p2 = p1;
    std::shared_ptr<int> p3 = p2;
    printf("====%d %d %d\n", *p1, *p2, *p3);
    p2 = std::make_shared<int>(200);
    p1 = p2;
    p3 = p2;
    printf("====%d %d %d\n", *p1, *p2, *p3);
    return 0;
}