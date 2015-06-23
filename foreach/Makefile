CC=gcc
CFLAGS=-L../lib/ -lhelpers -Wl,-rpath=../lib -I../lib/ -std=c99

all: foreach
	LD_LIBRARY_PATH="../lib"

clean:
	rm -f foreach

foreach: foreach.c
	$(CC) $< $(CFLAGS) -o $@
