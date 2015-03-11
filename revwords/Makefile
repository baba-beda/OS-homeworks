CC=gcc
CFLAGS=-Wall -fPIC -I.

all: revwords

clean:
	rm -f revwords

revwords: revwords.c
	$(CC) -o $@ -c $(CFLAGS) $<