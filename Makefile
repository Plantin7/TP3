CC=gcc
CFLAGS=-W -Wall -ansi


all: Exo1 Exo1bis Exo2

Exo1: Exo1.o
	$(CC) -o Exo1 Exo1.o 

Exo1.o: Exo1.c
	$(CC) -o Exo1.o -c Exo1.c $(CFLAGS)
	

Exo1bis: Exo1bis.o
	$(CC) -o Exo1bis Exo1bis.o 

Exo1bis.o: Exo1bis.c
	$(CC) -o Exo1bis.o -c Exo1bis.c $(CFLAGS)

Exo2: Exo2.o
	$(CC) -o Exo2 Exo2.o 

Exo2.o: Exo2.c
	$(CC) -o Exo2.o -c Exo2.c $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf Exo1
	rm -rf Exo1bis
	rm -rf Exo2
			
