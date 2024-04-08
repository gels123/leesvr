//
// Created by gels on 2024/4/2.
// 如何构造一个类使得只能在堆上或者栈上分配内存？
#include <stdio.h>
#include <stdlib.h>
#include <memory>

//只在栈上，可使new操作为private或者delete，这样就无法在堆上new
class ClsStack {
private:
    static void *operator new(size_t size) = delete;
    static void *operator new[](size_t size) = delete;

public:
    ClsStack() {
        printf("ClsStack\n");
    }
    ~ClsStack() {
        printf("~ClsStack\n");
    }
};

void f() {
    ClsStack obj;
//    ClsStack *p = new ClsStack(); //报错，无法堆上分配内存
}

//只在堆上分配内存,可使析构函数为private，因为堆上对象需要能调用析构函数，所以不能在堆上，只能在栈上，并提供public方法释放，为避免内存泄露，可将释放函数封装在智能指针中
class HeepOnly {
public:
    HeepOnly(){
        printf("HeepOnly\n");
    }
    static HeepOnly* Create() {
        return new HeepOnly();
    }
    static void Destory(HeepOnly *ins) {
        delete ins;;
    }
private:
    ~HeepOnly() {
        printf("~HeepOnly\n");
    }
};

void ff() {
    HeepOnly *p = new HeepOnly();
    HeepOnly::Destory(p);
//    HeepOnly obj; //报错，无法在栈上分配
}

class Test20240402 {
public:
    Test20240402() {
        printf("Test20240402\n");
    }
    ~Test20240402() {
        printf("~Test20240402\n");
    }
    void print() {
        printf("Test20240402 print\n");
    }
};

void fff() {
//    auto p = std::make_shared<Test20240402>();
//    std::shared_ptr<Test20240402> p2 = std::make_shared<Test20240402>();
//    p2.get()->print();
    std::shared_ptr<Test20240402> p3(new Test20240402());
    p3.get()->print();
}

class ClsReview {
public:
    ClsReview() { //构造
        num = 0;
        printf("ClsReview() %d\n", num);
    }
    ClsReview(int n) { //构造
        this->num = n;
        printf("ClsReview(int n) %d\n", num);
    }
    ~ClsReview() { //析构
        printf("~ClsReview() %d\n", num);
    }
    ClsReview(const ClsReview& c) { //赋值构造
        printf("ClsReview(const ClsReview& c)\n");
        this->num = c.num;
    }
    ClsReview& operator=(const ClsReview& c) { //赋值构造
        printf("ClsReview& operator=(const ClsReview& c)\n");
        if(this == &c) {
            return *this;
        }
        this->num = c.num;
        return *this;
    }
    ClsReview(ClsReview&& c) { // 移动构造
        printf("ClsReview(ClsReview&& c)\n");
        this->num = c.num;
    }
    ClsReview& operator=(ClsReview&& c) { // 移动赋值构造
        printf("ClsReview& operator=(ClsReview&& c)\n");
        if (this == &c) {
            return *this;
        }
        this->num = c.num;
        return *this;
    }
    static ClsReview createIns() {
        ClsReview c(666);
        return c;
    }
private:
    int num;
};

int main() {
    printf("== main begin ==\n");
    f();
    ff();
    fff();
    int i = 0, j=0;
    printf("++i=%d j++=%d\n", ++i, j++);
    printf("== main end ==\n");
    {
        ClsReview t1(100);
        ClsReview t2 = t1;
        ClsReview t3(200);
        t3 = t2;
        printf("-----1\n");
        ClsReview t4;
        t4 = ClsReview::createIns();
        printf("-----2\n");
//        ClsReview t5(t1.createIns());
//        printf("-----3\n");
    }

    return 0;
}