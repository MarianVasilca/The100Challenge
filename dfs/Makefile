CFLAGS = -Wall
CC = g++

build: dfs

dfs: dfs.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ dfs dfs.out
