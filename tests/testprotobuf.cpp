//
// Created by gels on 2024/3/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../game/proto/cpp/test.pb.h"

int main() {
    printf("main start\n");

    sTest t;
    t.set_uid(101);
    t.set_name("lalal");
    t.add_nums(98);
    t.add_nums(90);

    std::string str;
    t.SerializeToString(&str);
    printf("str=[%s]\n", str.c_str());

    sTest t2;
    t2.ParseFromString(str);
    printf("t2 uid=%d name=%s\n", t2.uid(), t2.name().c_str());

    printf("main end\n");
    return 0;
}