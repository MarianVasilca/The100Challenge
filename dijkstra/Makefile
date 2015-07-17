CFLAGS = -Wall
CC = g++

build: dijkstra

dijkstra: dijkstra.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ dijkstra dijkstra.out
