CFLAGS = -Wall
CC = g++

build: ctc

ctc: ctc.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ ctc ctc.out
