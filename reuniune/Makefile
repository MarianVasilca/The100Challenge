CFLAGS = -Wall
CC = g++

build: reuniune

reuniune: reuniune.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ reuniune reuniune.out
