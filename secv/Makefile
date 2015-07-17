CFLAGS = -Wall
CC = g++

build: secv

secv: secv.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ secv secv.out
