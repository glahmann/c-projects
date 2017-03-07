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
void readStocks(FILE *fptr, ListType stockList);
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
  ListType stockList;

  fptrClients = fopen("clients.txt", "r");
  fptrStocks = fopen("stocks.csv", "r");
  fptrStCl = fopen("stock_client.txt", "r");
  fptrSummary = fopen("summary.csv", "w");

  clientList = create_list(sizeof(struct client), compare);
  stockList = create_list(sizeof(struct stock), compare);

  readClients(fptrClients, clientList);
  readStocks(fptrStocks, stockList);

  fclose(fptrClients);
  fclose(fptrStocks);
  fclose(fptrStCl);
  fclose(fptrSummary);

  destroy_list(clientList);
  destroy_list(stockList);
}

void readClients(FILE *fptr,/*Pass by reference*/ ListType clientList) {
  int i = 0, idNum;
  char name[40], email[40], phone[15], line[95]; // TODO should be dynamic
  if (fptr == NULL) {
    fputs("Client file not found!", stderr);
    exit(-1);
  } else {
    while (fgets(line, 95, fptr) != NULL) { // TODO use alternative to 95
      sscanf(line, "%d ", &idNum);
      fgets(name, 40, fptr);
      fgets(email, 40, fptr);
      fgets(phone, 15, fptr);
      // create a client object
      Client curr = createClient(idNum, name, email, phone);
      // add client object pointer to list
      push(clientList, &curr);
      Client *cli = (Client *) get_element(clientList, i);
      printf("%d\n", cli->idNum);
      i++;
    }
    printf("%d\n", size_is(clientList));
  }
}

void readStocks(FILE *fptr,/*Pass by reference*/ ListType stockList) {
  char symbol[6], line[95];   // TODO should be dynamic
  int i = 0;
  double price;
  if (fptr == NULL) {
    fputs("Stock file not found!", stderr);
    exit(-1);
  } else {
    fgets(line, 95, fptr);
    while (fgets(line, 95, fptr) != NULL) { // TODO use alternative to 95
      sscanf(line, "%[^,],%lf", symbol, &price);

      // create a stock object
      Stock curr = createStock(symbol, price);
      // add stock object pointer to list
      push(stockList, &curr);
      if(i%20 == 0) { // TODO remove
	Stock *stk = (Stock *) get_element(stockList, i);
	printf("%lf\n", stk->price);
      }
      i++;
    }
    printf("%d\n", size_is(stockList));
  }
}

int compare(int *a, int *b) {
  short int output = 0;
  if (*a < *b)
    output = -1;
  else if (*a > *b)
    output = 1;
  return output;
}
