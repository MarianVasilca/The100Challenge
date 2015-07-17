CFLAGS = -Wall
CC = g++

build: sortaret

sortaret: sortaret.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ sortaret sortaret.out
