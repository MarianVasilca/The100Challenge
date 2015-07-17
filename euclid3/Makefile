CFLAGS = -Wall
CC = g++

build: euclid3

aplusb: euclid3.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ euclid3 euclid3.out
