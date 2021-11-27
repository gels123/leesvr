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
	cd ./3rd/hiredis;make
	mv ./3rd/hiredis/*.so ./lib/
	@echo "========== make hiredis end =========="

	@echo "\n\n========== make libco start =========="
	cd ./3rd/libco;make
	mv ./3rd/libco/solib/*.so ./lib/
	@echo "========== make libco end =========="

	@echo "\n\n========== make zlog start =========="
	cd ./3rd/zlog;make
	mv ./3rd/zlog/src/*.so* ./lib/
	@echo "========== make zlog end =========="

test:

clean:
	@echo "========== clean ./ start =========="
	rm -rf *.o *.so
	@echo "========== clean ./ end =========="

	@echo "========== clean hiredis start =========="
	cd ./3rd/hiredis;make clean
	@echo "========== clean hiredis end =========="

	@echo "========== clean libco start =========="
	cd ./3rd/libco;make clean
	@echo "========== clean libco end =========="

	@echo "========== clean zlog start =========="
	cd ./3rd/zlog;make clean
	@echo "========== clean zlog end =========="

