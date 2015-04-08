CFLAGS = -Wall
CC = g++

build: cifra

aplusb: cifra.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ cifra cifra.out
