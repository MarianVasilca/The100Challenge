CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: sate

sate: sate.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ sate sate.out
