CFLAGS = -Wall
CC = g++

build: text

text: text.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ text text.out
