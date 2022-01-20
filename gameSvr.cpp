/**
 * g++ -o main -g -rdynamic main.cpp mySignal.cpp
 * 
 * addr2line -e ./mySignalTest 0x400a84 //查看地址对应的代码行
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>	    /* for signal */
#include <execinfo.h> 	/* for backtrace() */
#include "game/utils/mySignal.h"

int main(int argc, char* argv[]) 
{
    //init signal handler
    MySignal::InitSignal();

    int i = 0;
    while((i++) <= 10000) {
        sleep(1);
    }

    return 0;
}
