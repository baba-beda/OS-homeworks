CC=gcc
CFLAGS=-Wall -std=c99 -I    .

all: revwords

clean:
	rm -f revwords

revwords: revwords.c
	$(CC) -o $@ $(CFLAGS) $<