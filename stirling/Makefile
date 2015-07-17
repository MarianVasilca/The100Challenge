CFLAGS = -Wall
CC = g++

build: stirling

stirling: stirling.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ stirling stirling.out
