CFLAGS = -Wall
CC = g++

build: lgput

lgput: lgput.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ lgput lgput.out
