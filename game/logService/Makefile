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
	

test:
	g++ -c -o testZlog.o testZlog.cpp -I../../3rd/zlog/src
	g++ -o testZlog testZlog.o -L../../lib -lzlog -lpthread -rdynamic -Wl,-rpath,../../lib
	
clean:
	rm -rf *.o *.so

