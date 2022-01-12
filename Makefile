.PHONY: all linux clean

CC     = g++
TARGET = gameSvr
CFLAGS = -g -rdynamic -O3 -Wall -pedantic -DNDEBUG -std=c++11 -I./game/utils

LDFLAGS = -I./game/utils -L./libso -lutils -Wl,-rpath=./libso

.cpp.o:
	$(CC) -c $(CFLAGS) -o $@ $<

all:
	@echo "Usage: $(MAKE) <platform>"
	@echo "  * linux"
	@echo "  * clean"

linux:
	# @echo "\n\n========== make hiredis start =========="
	# cd lib/hiredis;make
	# mv lib/hiredis/*.so lib/
	# @echo "========== make hiredis end =========="

	@echo "\n\n========== make libco start =========="
	#cd lib/libco;make libcolib.so
	#mv lib/libco/solib/*.so lib/
	@echo "========== make libco end =========="

	# @echo "\n\n========== make zlog start =========="
	# cd lib/zlog;make
	# mv lib/zlog/src/*.so* lib/
	# @echo "========== make zlog end =========="

	# @echo "\n\n========== make libevent start =========="
	# cd lib/libevent;autoreconf --install;autoconf configure.ac;./configure;make
	# @echo "========== make zlog end =========="

	@echo "\n\n========== make utils start =========="
	cd game/utils;make linux
	@echo "========== make utils end =========="

	@echo "\n\n========== make main start =========="
	@echo pwd=$(PWD)
	$(CC) -o $(TARGET) gameSvr.cpp $(LDFLAGS)
	@echo "========== make main end =========="

clean:
	@echo "========== clean ./ start =========="
	rm -rf *.o *.so
	@echo "========== clean ./ end =========="

	@echo "========== clean hiredis start =========="
	cd lib/hiredis;make clean
	@echo "========== clean hiredis end =========="

	@echo "========== clean libco start =========="
	cd lib/libco;make clean
	@echo "========== clean libco end =========="

	@echo "========== clean zlog start =========="
	cd lib/zlog;make clean
	@echo "========== clean zlog end =========="

	@echo "========== clean utils start =========="
	cd game/utils;make clean
	@echo "========== clean utils end =========="

	@echo "========== clean main start =========="
	rm -rf *.o *.so $(TARGET)
	@echo "========== clean main end =========="


