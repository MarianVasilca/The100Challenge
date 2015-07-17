CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: kperm

kperm: kperm.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ kperm kperm.out
