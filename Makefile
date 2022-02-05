CC=gcc
CFLAGS=gtk+-3.0
LIBS=gtk+-3.0

clean:
	rm -f game.o

install: 
	$(CC) game.c -o game.o `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
