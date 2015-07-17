CFLAGS = -Wall
CC = g++

build: euclid2

euclid2: euclid2.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ euclid2 euclid2.out
