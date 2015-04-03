CC=gcc
CFLAGS=-L../lib/ -lhelpers -std=c99 -Wl,-rpath=../lib -I../lib/

all: bufcat
	LD_LIBRARY_PATH="../lib"

clean:
	rm -f bufcat

bufcat: bufcat.c
	$(CC) $< $(CFLAGS) -o $@
