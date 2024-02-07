//
// Created by gels on 2024/1/16.
//
#include <iostream>
#include <stdio.h>
using namespace std;

class T {
public:
    T() {
        printf("==构造==\n");
        num = 0;
    }
    T(int n) {
        printf("==构造==\n");
        num = n;
    }
    T(const T& t) {
        printf("==拷贝构造==\n");
        num = t.num;
    }
    T& operator=(const T& t) {
        printf("==拷贝赋值构造==\n");
        num = t.num;
        return *this;
    }
    T(T&& t) {
        printf("==移动构造==\n");
        num = t.num;
    }
    T& operator=(T&& t) {
        printf("==移动赋值构造==\n");
        num = t.num;
        return *this;
    }
    T createT(int num) {
        T t;
        t.num = num;
        return t;
    }
    void fvalue(int& n) {
        printf("lvalue n=%d\n", n);
    }
    void fvalue(int&& n) {
        printf("lvalue n=%d\n", n);
    }
private:
    int num;
};
template<typename X>
void ffvalue(X& x) {
    printf("ffvalue x=%d\n", x);
}
template<typename X>
void ffvalue(X&& x) {
    printf("ffvalue x=%d\n", x);
}
template<typename X>
void call_ffvalue(X&& x) {
    ffvalue(std::forward<X>(x)); // 完美转发, X&&万能引用
}

int main(int argc, char** argv)
{
    printf("main=\n");
    T t1(100); // 构造t1
    T t2 = t1; // 拷贝构造t2
    T t3(200);
    t3 = t2; // 赋值构造
    t3 = t1.createT(300); // 移动赋值构造

    //左值右值测试
    int num0 = 100;
    int& num1 = num0;
    int&& num2 = 200;
    t3.fvalue(num1);
    t3.fvalue(static_cast<int&&>(num2));
    //完美转发测试

    int num = 0x00636261;//用16进制表示32位int，0x61是字符'a'的ASCII码
    int * pnum = &num;
    char* str = reinterpret_cast<char*> (pnum);
    cout<<"pnum指针的值: "<<pnum<<endl; //0x7ff7bba296a0
    cout<<"pstr指针的值: "<<static_cast<void *>(str)<<endl;//直接输出pstr会输出其指向的字符串，这里的类型转换是为了保证输出pstr的值 0x7ff7bba296a0
    cout<<"pnum指向的内容: "<<hex<<*pnum<<endl; //636261
    cout<<"pstr指向的内容: "<<str<<endl; //abc

    int m1 = 100;
    int& m2 = m1;
    int&& m3 = 200;
    ffvalue(static_cast<int&>(m2));
    ffvalue(static_cast<int&&>(m3));
    call_ffvalue(m2);
    call_ffvalue(m3);

    return 0;
}