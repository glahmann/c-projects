/**
 * Driver for Project 4
 */
#include <stdio.h>
#include <stdlib.h>
#include "clientADT.h"
#include "listADTgen.h"
#include "stockADT.h"

//
// pre:
// post:
int compare(int*, int*);
//
// pre:
// post:
ListType readClients(FILE *fptr);
//
// pre:
// post:
void readTXT();


int main(void) {
  FILE *fptrClients;
  FILE *fptrStocks;
  FILE *fptrStCl;
  FILE *fptrSummary; // TODO chan

  fptrClients = fopen("clients.txt", "r");
  fptrStocks = fopen("stocks.csv", "r");
  fptrStCl = fopen("stock_client.txt", "r");
  fptrSummary = fopen("summary.csv", "w");

  readClients(fptrClients);

  fclose(fptrClients);
  fclose(fptrStocks);
  fclose(fptrStCl);
  fclose(fptrSummary);
}

ListType readClients(FILE *fptr) {
  ListType clientList;
  Client aClient;
  if (fptr == NULL) {
    fputs("Client file not found!", stderr);
    exit(-1);
  } else {
    clientList = createList(61, compare);
  }
  return clientList;
}

void readTXT() {

}

int compare(int *a, int *b) {
  short int output = 0;
  if (*a < *b)
    output = -1;
  else if (*a > *b)
    output = 1;
  return output;
}
