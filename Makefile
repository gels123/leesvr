##########################################################################################
# Compile commands
##########################################################################################
.PHONY: all linux test clean

all:
	@echo "Usage: $(MAKE) <platform>"
	@echo "  * linux"
	@echo "  * test"
	@echo "  * clean"

linux:
	@echo "\n\n========== make hiredis start =========="
	cd ./lib/hiredis;make
	mv ./lib/hiredis/*.so ./lib/
	@echo "========== make hiredis end =========="

	@echo "\n\n========== make libco start =========="
	cd ./lib/libco;make
	mv ./lib/libco/solib/*.so ./lib/
	@echo "========== make libco end =========="

	@echo "\n\n========== make zlog start =========="
	cd ./lib/zlog;make
	mv ./lib/zlog/src/*.so* ./lib/
	@echo "========== make zlog end =========="

	@echo "\n\n========== make libevent start =========="
	cd ./lib/libevent;autoreconf --install;autoconf configure.ac;./configure;make
	@echo "========== make zlog end =========="

test:

clean:
	@echo "========== clean ./ start =========="
	rm -rf *.o *.so
	@echo "========== clean ./ end =========="

	@echo "========== clean hiredis start =========="
	cd ./lib/hiredis;make clean
	@echo "========== clean hiredis end =========="

	@echo "========== clean libco start =========="
	cd ./lib/libco;make clean
	@echo "========== clean libco end =========="

	@echo "========== clean zlog start =========="
	cd ./lib/zlog;make clean
	@echo "========== clean zlog end =========="

