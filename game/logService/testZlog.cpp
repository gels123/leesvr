/**
 * @file testzlog.cpp
 * @author gels
 * @brief 
 * @version 0.1
 * @date 2021-11-27
 * 
 * @copyright Copyright (c) 2021
 * 
 * compile:
 * rm *.o *.so testZlog
 * g++ -c -o testZlog.o testZlog.cpp -I../../3rd/zlog/src
 * g++ -o testZlog testZlog.o -L../../lib -lzlog -lpthread -rdynamic -Wl,-rpath,../../lib
 */

#include <stdio.h>
#include <iostream>
#include "zlog.h"

int main(int argc, char** argv)
{
	int rc;
	zlog_category_t *c;

	rc = zlog_init("./zlogRelease.conf");
	if (rc) {
		printf("init failed\n");
		return -1;
	}

	c = zlog_get_category("my_cat");
	if (!c) {
		printf("get cat fail\n");
		zlog_fini();
		return -2;
	}

	zlog_info(c, "hello, zlog");

	zlog_fini();

	return 0;
} 