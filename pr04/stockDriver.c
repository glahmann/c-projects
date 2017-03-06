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
void readClients(FILE *fptr, ListType clientList);
//
// pre:
// post:
void readTXT();


int main(void) {
  FILE *fptrClients;
  FILE *fptrStocks;
  FILE *fptrStCl;
  FILE *fptrSummary; // TODO chan
  int i;
  ListType clientList;

  fptrClients = fopen("clients.txt", "r");
  fptrStocks = fopen("stocks.csv", "r");
  fptrStCl = fopen("stock_client.txt", "r");
  fptrSummary = fopen("summary.csv", "w");

  // sizeof(int) == sizeof(pointer) == 4 bytes
  clientList = createList(sizeof(int), compare);
  readClients(fptrClients, clientList);

  fclose(fptrClients);
  fclose(fptrStocks);
  fclose(fptrStCl);
  fclose(fptrSummary);

  // Destroy elements of list
  for (i = 0; i < size_is(clientList); i++) {
    destroyClient((Client) get_element(clientList, i));
  }
  destroyList(clientList);
}

void readClients(FILE *fptr,/*Pass by reference*/ ListType clientList) {
  int i = 0, idNum;
  char name[95], email[95], phone[95], line[95];
  if (fptr == NULL) {
    fputs("Client file not found!", stderr);
    exit(-1);
  } else {
    while (fgets(line, 95, fptr) != NULL) { // TODO use alternative to 95
      sscanf(line, "%d", &idNum);
      fgets(name, 95, fptr);
      fgets(email, 95, fptr);
      fgets(phone, 95, fptr);
      // create a client object
      Client curr = createClient(idNum, name, email, phone);
      // add client object pointer to list
      push(clientList, curr);
    }
    printf("%d\n", size_is(clientList));
  }
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
