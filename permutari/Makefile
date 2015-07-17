CFLAGS = -Wall
CC = g++

build: permutari

permutari: permutari.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ permutari permutari.out
