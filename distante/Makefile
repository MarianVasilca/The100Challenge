CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: distante

distante: distante.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ distante distante.out
