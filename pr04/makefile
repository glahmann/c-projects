pr4.out: stockDriver.o clientADT.o stockADT.o listADTgen.o
	gcc -o -std=gnu90 pr4.out stockDriver.o clientADT.o stockADT.o listADTgen.o

stockDriver.o: stockDriver.c clientADT.h stockADT.h listADTgen.h #more dependencies?
	gcc -g -std=gnu90 -c stockDriver.c

clientADT.o: clientADT.c clientADT.h
	gcc -g -std=gnu90 -c clientADT.c

stockADT.o: stockADT.c stockADT.h
	gcc -g -std=gnu90 -c stockADT.c

listADTgen.o: listADTgen.c listADTgen.h
	gcc -g -std=gnu90 -c listADTgen.c

clean:
	rm -f pr4.out stockDriver.o clientADT.o stockADT.o listADTgen.o
