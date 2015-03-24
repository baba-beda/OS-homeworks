CC=gcc
CFLAGS=-L../lib/ -lhelpers -std=c99 -Wl,-rpath=../lib -I../lib/

all: revwords
	LD_LIBRARY_PATH="../lib"

clean:
	rm -f revwords

revwords: revwords.c
	$(CC) $< $(CFLAGS) -o $@
