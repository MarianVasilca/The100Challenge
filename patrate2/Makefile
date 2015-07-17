CFLAGS = -Wall
CC = g++

build: patrate2

patrate2: patrate2.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ patrate2 patrate2.out
