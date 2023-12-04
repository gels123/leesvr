/**
 * g++ -o mySignalTest -g -rdynamic mySignalTest.cpp mySignal.cpp
 * 
 * addr2line -e ./mySignalTest 0x400a84 //查看地址对应的代码行
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>	    /* for signal */
#include <execinfo.h> 	/* for backtrace() */
#include "Signal.h"

void dev(int n, int m) {
    int a = n/m;
}

int main(int argc, char* argv[]) 
{
    // 程序异常终止
    signal(SIGABRT, MySignal::SignalHandler);
    // 非法访问存储器
    signal(SIGSEGV, MySignal::SignalHandler);
    // 算术运算出错, 如除数为0或溢出
    signal(SIGFPE, MySignal::SignalHandler);
    // 非法函数映象，如非法指令
    signal(SIGILL, MySignal::SignalHandler);
    // 中断信号, 如 ctrl-C
    signal(SIGINT, MySignal::SignalHandler);
    // 非法访问存储器, 如访问不存在的内存单元
    signal(SIGSEGV, MySignal::SignalHandler);
    // 发送给本程序的终止请求信号
    signal(SIGTERM, MySignal::SignalHandler);

    dev(100, 0);
    
    int i = 0;
    while((i++) <= 60) {
        sleep(1);
    }

    return 0;
}
