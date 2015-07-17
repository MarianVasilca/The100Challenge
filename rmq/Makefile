CFLAGS = -Wall
CC = g++

build: rmq

rmq: rmq.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ rmq rmq.out
