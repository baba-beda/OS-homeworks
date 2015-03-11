CC=gcc
CFLAGS=-Wall -fPIC -std=c99 -I.

all: libhelpers.so

clean:
	rm -f libhelpers.so
	rm -f helpers.o

libhelpers.so: helpers.o
	$(CC) -o $@ -shared $<

helpers.o: helpers.c
	$(CC) -o $@ -c $(CFLAGS) $<