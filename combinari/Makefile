CFLAGS = -Wall
CC = g++

build: combinari

combinari: combinari.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ combinari combinari.out
