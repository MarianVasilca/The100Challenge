CFLAGS = -Wall
CC = g++

build: aria

aria: aria.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ aria aria.out
