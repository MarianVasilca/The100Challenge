CFLAGS = -Wall
CC = g++

build: submultimi

submultimi: submultimi.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ submultimi submultimi.out
