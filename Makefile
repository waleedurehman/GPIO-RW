CC=gcc
CFLAGS=-Wall -g 

all: test.sh

test.sh: toggle
	./test.sh

libtoggle.so: libtoggle.o 
	$(CC) $(CFLAGS) libtoggle.o -shared -o libtoggle.so

libtoggle.o: libtoggle.c toggle.h
	$(CC) $(CFLAGS) -c -fPIC libtoggle.c -o libtoggle.o

toggle: toggle.c toggle.h libtoggle.so
	$(CC) $(CFLAGS) -o toggle toggle.c toggle.h libtoggle.so

clean:
	rm -rf libtoggle.so libtoggle.o toggle

