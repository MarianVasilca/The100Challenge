CFLAGS = -Wall
CC = g++

build: bfs

bfs: bfs.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ bfs bfs.out
