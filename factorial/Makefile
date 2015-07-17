CFLAGS = -Wall
CC = g++

build: factorial

aplusb: factorial.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ factorial factorial.out
