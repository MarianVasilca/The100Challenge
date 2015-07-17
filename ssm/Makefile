CFLAGS = -Wall -Wmaybe-uninitialized -Wextra
CC = g++

build: ssm

ssm: ssm.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ ssm ssm.out
