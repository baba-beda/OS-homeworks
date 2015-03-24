CC=gcc
CFLAGS=-L../lib/ -lhelpers -Wl,-rpath=../lib -I../lib/ -std=c99

all: filter
	LD_LIBRARY_PATH="../lib"

clean:
	rm -f filter

filter: filter.c
	$(CC) $< $(CFLAGS) -o $@
