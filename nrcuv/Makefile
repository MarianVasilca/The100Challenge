CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: nrcuv

nrcuv: nrcuv.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ nrcuv nrcuv.out
