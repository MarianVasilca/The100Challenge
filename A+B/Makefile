CFLAGS = -Wall
CC = g++

build: aplusb

aplusb: A+B.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ aplusb adunare.out