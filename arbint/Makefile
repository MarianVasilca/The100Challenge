CFLAGS = -Wall
CC = g++

build: arbint

arbint: arbint.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ arbint arbint.out
