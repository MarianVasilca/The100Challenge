CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: cautbin

cautbin: cautbin.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ cautbin cautbin.out
