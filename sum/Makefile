CFLAGS = -Wall
CC = g++

build: sum

sum: sum.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ sum sum.out
