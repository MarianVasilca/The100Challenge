CFLAGS = -Wall
CC = g++

build: cuburi3

cmmdc: cuburi3.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ cuburi3 cuburi3.out