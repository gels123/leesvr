CC = g++
CPPFLAG = -g -O2 -Wall -std=c++11

.PHONY: clean c4.exe c9.exe

.cpp.o:
	$(CC) -c $(CPPFLAG) -o $@ $<

.cpp.o:
	$(CC) -c $(CPPFLAG) -o $@ $<

c4.exe: c4.o
	$(CC) -o $@ $^

c9.exe: c9.o
	$(CC) -o $@ $^

clean:
	rm -rf *.o *.so *.exe *.out
