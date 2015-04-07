CFLAGS = -Wall
CC = g++

build: cmmdc

cmmdc: cmmdc.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ cmmdc cmmdc.out