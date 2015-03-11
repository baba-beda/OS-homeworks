CC=gcc
CFLAGS=-Wall -fPIC -I.

all: cat

clean:
	rm -f cat

cat: cat.c
	$(CC) -o $@ -c $(CFLAGS) $<