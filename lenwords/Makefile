CC=gcc
CFLAGS=-L../lib/ -lhelpers -Wl,-rpath=../lib -std=c99

all: lenwords
	LD_LIBRARY_PATH="../lib"

clean:
	rm -f lenwords

lenwords: lenwords.c
	$(CC) $< $(CFLAGS) -o $@
