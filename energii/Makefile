CFLAGS = -Wall
CC = g++

build: energii

energii: energii.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ energii energii.out
