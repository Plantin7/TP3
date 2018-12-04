CC=gcc
CFLAGS=-W -Wall -ansi


all: Exo1 Exo1bis Exo2 Exo3 Exo4 Exo5

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

Exo3: Exo3.o
	$(CC) -o Exo3 Exo3.o 

Exo3.o: Exo3.c
	$(CC) -o Exo3.o -c Exo3.c $(CFLAGS)

Exo4: Exo4.o
	$(CC) -o Exo4 Exo4.o 

Exo4.o: Exo4.c
	$(CC) -o Exo4.o -c Exo4.c $(CFLAGS)

Exo5: Exo5.o
	$(CC) -o Exo5 Exo5.o 

Exo5.o: Exo5.c
	$(CC) -o Exo5.o -c Exo5.c $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf Exo1
	rm -rf Exo1bis
	rm -rf Exo2
	rm -rf Exo3
	rm -rf Exo4
	rm -rf Exo5
			
