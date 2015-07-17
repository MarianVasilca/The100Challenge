CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: aprindere

aprindere: aprindere.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ aprindere aprindere.out
