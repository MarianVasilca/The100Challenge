CFLAGS = -Wall
CC = g++

build: ciur

aplusb: ciur.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ ciur ciur.out
