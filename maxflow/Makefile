CFLAGS = -Wall
CC = g++

build: maxflow

maxflow: maxflow.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ maxflow maxflow.out
