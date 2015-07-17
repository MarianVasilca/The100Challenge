CFLAGS = -Wall
CC = g++

build: rucsac

rucsac: rucsac.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ rucsac rucsac.out
