CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: cmlsc

cmlsc: cmlsc.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ cmlsc cmlsc.out
