//
// Created by gels on 2024/1/23.
//
//
// Created by gels on 2024/1/23.
//
#include<iostream>
#include "stdio.h"
#include <thread>

class TestNew {
public:
    static void* operator new(std::size_t sz) {
        printf("==TestNew operator new==\n");
        return std::malloc(sz);
    }
    static void* operator new(std::size_t sz, void* ptr) {
        printf("==TestNew placement new==\n");
        return ptr;
    }
    static void operator delete(void* ptr) {
        printf("==TestNew operator delete==\n");
        std::free(ptr);
    }
    TestNew() {
        printf("==TestNew ctor==\n");
        num = 0;
    }
    int getNum() {
        return num;
    }
private:
    int num;
};

int main() {
    auto p = new TestNew();
    std::cout << "sizeof(p)=" << sizeof(p) << "p->num=" << p->getNum() << std::endl;
    delete p;
    auto ptr = std::malloc(sizeof (TestNew));
    p = new(ptr) TestNew();
    std::cout << "sizeof(p)=" << sizeof(p) << "p->num=" << p->getNum() << std::endl;
    delete p;

    return 0;
}