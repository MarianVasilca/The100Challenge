CFLAGS = -Wall
CC = g++

build: algsort

algsort: algsort.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ algsort algsort.out
