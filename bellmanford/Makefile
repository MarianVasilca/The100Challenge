CFLAGS = -Wall -g
CC = g++

build: bellmanford

bellmanford: bellmanford.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ bellmanford bellmanford.out
