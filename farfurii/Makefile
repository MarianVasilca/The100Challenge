CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: farfurii

farfurii: farfurii.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ farfurii farfurii.out
