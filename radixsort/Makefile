CFLAGS = -Wall
CC = g++

build: radixsort

radixsort: radixsort.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ radixsort radixsort.out
