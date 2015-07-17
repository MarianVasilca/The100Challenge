CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: divk

divk: divk.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ divk divk.out
