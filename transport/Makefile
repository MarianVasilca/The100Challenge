CFLAGS = -Wall
CC = g++

build: transport

transport: transport.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ transport transport.out
