# makefile for rational ADT client

myexe: client.o rational.o
	gcc -o myexe client.o rational.o


client.o: client.c rational.h
	gcc -std=gnu90 -c client.c

rational.o: rational.c rational.h
	gcc -std=gnu90 -c rational.c 