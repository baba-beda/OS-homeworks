CC=gcc
CFLAGS=-L../lib/ -lhelpers

all: cat
	LD_LIBRARY_PATH="../lib"

clean:
	rm -f cat

cat: cat.c
	$(CC) $< $(CFLAGS) -o $@
