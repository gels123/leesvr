//
// Created by gels on 2021/12/24.
//

#include <stdio.h>
#include <iostream>

int main(int arg, char **args)
{
    const int num = 100;
    const int * ptr;
    ptr = &num;
    std::cout << *ptr << std::endl;

    return 0;
}