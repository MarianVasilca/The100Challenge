CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: divprim

divprim: divprim.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ divprim divprim.out
