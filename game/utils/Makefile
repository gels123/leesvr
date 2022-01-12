CC     = g++
TARGET = ../../libso/libutils.so
CFLAGS = -g -rdynamic -O3 -Wall -pedantic -DNDEBUG -std=c++11 -fPIC

LNX_LDFLAGS = -shared
MAC_LDFLAGS = -bundle -undefined dynamic_lookup

LDFLAGS = $(MYLDFLAGS)

OBJS    = utils.o mySignal.o

all:
	@echo "Usage: $(MAKE) <platform>"
	@echo "  * linux"
	@echo "  * macosx"
	@echo "  * clean"

.cpp.o:
	$(CC) -c $(CFLAGS) -o $@ $<

linux:
	@$(MAKE) $(TARGET) MYLDFLAGS="$(LNX_LDFLAGS)"

macosx:	
	@$(MAKE) $(TARGET) MYLDFLAGS="$(MAC_LDFLAGS)"

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

clean:
	rm -rf *.o *.so

