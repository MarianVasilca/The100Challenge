CFLAGS = -Wall
CC = g++

build: fractal

fractal: fractal.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ fractal fractal.out
