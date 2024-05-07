//
// Created by gels on 2021/12/24.
//

#include <stdio.h>
#include <iostream>
#include <memory>

template<typename T>
void tmpf(T& t) {
    printf("fasdfsdf===1 %d\n", t);
}
template<typename T>
void tmpf(T&& t) {
    printf("fasdfsdf===2 %d\n", t);
}

int main(int arg, char **args)
{
    int num1 = 100;
    tmpf(num1);
    int& num2 = num1;
    tmpf(std::forward<int>(num2)); // 完美转发 同tmpf(num2) 同tmpf(static_cast<int&>(num2));
    int&& num3 = 300;
    tmpf(std::forward<int>(num3)); // 完美转发 同tmpf(static_cast<int&&>(num3));


    return 0;
}