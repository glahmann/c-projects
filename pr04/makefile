pr4.out: stockDriver.o clientADT.o stockADT.o listADTgen.o
	gcc -std=gnu90 -o pr4.out stockDriver.o clientADT.o stockADT.o listADTgen.o

stockDriver.o: stockDriver.c clientADT.h stockADT.h listADTgen.h #more dependencies?
	gcc -std=gnu90 -c stockDriver.c

clientADT.o: clientADT.c clientADT.h
	gcc -std=gnu90 -c clientADT.c

stockADT.o: stockADT.c stockADT.h
	gcc -std=gnu90 -c stockADT.c

listADTgen.o: listADTgen.c listADTgen.h
	gcc -std=gnu90 -c listADTgen.c
