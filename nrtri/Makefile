CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: nrtri

nrtri: nrtri.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ nrtri nrtri.out
