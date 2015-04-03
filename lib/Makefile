CC=gcc
CFLAGS=-Wall -fPIC -std=c99 -I.

all: libhelpers.so libbufio.so

clean:
	rm -f libhelpers.so
	rm -f helpers.o
	rm -f bufio.o
	rm -f libbufio.sp

libbufio.so: bufio.o
	$(CC) -o $@ -shared $<

bufio.o: bufio.c
	$(CC) -o $@ -c $(CFLAGS) $<

libhelpers.so: helpers.o
	$(CC) -o $@ -shared $<

helpers.o: helpers.c
	$(CC) -o $@ -c $(CFLAGS) $<