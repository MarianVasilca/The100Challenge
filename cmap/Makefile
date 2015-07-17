CFLAGS = -Wall
CC = g++

build: cmap

cmap: cmap.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ cmap cmap.out
