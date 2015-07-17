CFLAGS = -Wall
CC = g++

build: aib

aib: aib.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ aib aib.out
