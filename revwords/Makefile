CC=gcc
CFLAGS=-L../lib/ -lhelpers -std=c99

all: revwords
	LD_LIBRARY_PATH="../lib"

clean:
	rm -f revwords

revwords: revwords.c
	$(CC) $< $(CFLAGS) -o $@
