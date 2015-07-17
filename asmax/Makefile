CFLAGS = -Wall
CC = g++

build: asmax

asmax: asmax.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ asmax asmax.out
