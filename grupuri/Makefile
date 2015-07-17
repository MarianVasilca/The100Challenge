CFLAGS = -Wall
CC = g++

build: grupuri

grupuri: grupuri.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ grupuri grupuri.out
