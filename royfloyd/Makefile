CFLAGS = -Wall
CC = g++

build: royfloyd

royfloyd: royfloyd.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ royfloyd royfloyd.out
