#makefile for rescuebin

rescuebin: driver.o animals.o
	gcc -o rescuebin driver.o animals.o

driver.o: driver.c animals.h
	gcc -c -g -std=gnu90 driver.c

animals.o: animals.c animals.h
	gcc -c -g -std=gnu90 animals.c

clean:
	rm -f rescuebin driver.o animals.o
