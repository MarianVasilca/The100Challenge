CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: dezastru

dezastru: dezastru.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ dezastru dezastru.out
