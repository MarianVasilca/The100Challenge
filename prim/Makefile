CFLAGS = -Wall
CC = g++

build: prim

aplusb: prim.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ prim prim.out
