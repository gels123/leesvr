#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "Utils.h"
#include "hiredis.h"
#include "co/log.h"
#include "co/cout.h"
#include "co/time.h"

int nested_log() {
    DLOG << ">>>> nested log..";
    return 123;
}

int main() {
    std::cout << "Hello, World! Time=" << Utils::getTimestamp() << std::endl;

    DLOG << "This is DLOG (debug).. " << 23;
    LOG  << "This is LOG  (info).. " << 23;
    WLOG << "This is WLOG (warning).. " << 23;
    ELOG << "This is ELOG (error).. " << 23;
    FLOG << "This is FLOG (fatal).. " << 23;
    LOG << "hello " << nested_log() << "  " << nested_log();
    TLOG("co") << "hello co";
    TLOG("bob") << "hello bob";


    return 0;
}
