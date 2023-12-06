#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "Utils.h"
#include "hiredis.h"
#include "zlog.h"

int main() {
    std::cout << "Hello, World! Time=" << Utils::getTimestamp() << std::endl;

    char buf[128];
    getcwd(buf, sizeof(buf));
    printf("current working directory: %s\n", buf);

    int rc;
    zlog_category_t *c;

    rc = zlog_init("../game/logger/logger.conf");
    if (rc) {
        printf("init failed\n");
        return -1;
    }

    c = zlog_get_category("gamed");
    if (!c) {
        printf("get cat fail\n");
        zlog_fini();
        return -2;
    }
    while(1) {
        zlog_debug(c, "hello, zlog");
        zlog_info(c, "hello, zlog");
        zlog_notice(c, "hello, zlog");
        zlog_warn(c, "hello, zlog");
        zlog_error(c, "hello, zlog");
        sleep(1);
    }

    zlog_fini();

    return 0;
}
