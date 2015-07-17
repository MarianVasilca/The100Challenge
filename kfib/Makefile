CFLAGS = -Wall
CC = g++

build: kfib

kfib: kfib.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ kfib kfib.out
