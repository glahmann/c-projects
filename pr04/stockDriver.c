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
int compare(const void *a, const void *b);
//
// pre:
// post:
void printItem(Client *cli);
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

  // Open relevant files for reading and writing
  fptrClients = fopen("clients.txt", "r");
  fptrStocks = fopen("stocks.csv", "r");
  fptrStCl = fopen("stock_client.txt", "r");
  fptrSummary = fopen("summary.csv", "w");

  // Allocate memory for and populate lists
  clientList = create_list(sizeof(struct client), compare);
  stockList = create_list(sizeof(struct stock), compare);
  readClients(fptrClients, clientList);
  readStocks(fptrStocks, stockList);

  sort_list(clientList);
  print_list(clientList, printItem);
  // for (i=0; i<size_is(clientList); i++) {
  //
  // }

  // Close all files
  fclose(fptrClients);
  fclose(fptrStocks);
  fclose(fptrStCl);
  fclose(fptrSummary);

  // Free lists
  make_empty(clientList);
  make_empty(stockList);
  destroy_list(clientList);
  destroy_list(stockList);
}

void readClients(FILE *fptr,/*Pass by reference*/ ListType clientList) {
  printf("3)ok");
  int i = 0, idNum;
  char name[40], email[40], phone[15], line[95]; // TODO should be dynamic
  if (fptr == NULL) {
    fputs("Client file not found!", stderr);
    exit(-1);
  } else {
    printf("4)ok");
    while (fgets(line, 95, fptr) != NULL) { // TODO use alternative to 95
      sscanf(line, "%d ", &idNum);
      fgets(name, 40, fptr);
      fgets(email, 40, fptr);
      fgets(phone, 15, fptr);
      printf("5)ok");
      // create a client object
      Client curr = createClient(idNum, name, email, phone);
      // add client object pointer to list
      push(clientList, &curr);
      // Client *cli = (Client *) get_element(clientList, i);
      // printf("%d\n", cli->idNum);
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
    while (fgets(line, 95, fptr) != NULL) { // TODO use alternative to 95
      sscanf(line, "%[^,]s%lf", symbol, &price); // TODO store both as strings? Better memory usage.

      // create a stock object
      Stock curr = createStock(symbol, price);
      // add stock object pointer to list
      push(stockList, &curr);
      // Stock *stk = (Stock *) get_element(stockList, i);
      // printf("%lf\n", stk->price);
      i++;
    }
    printf("%d\n", size_is(stockList));
  }
}

int compare(const void *a, const void *b) {
  int c = ((Client *) a)->idNum;
  int d = ((Client *) b)->idNum;

  return (c - d);
}

void printItem(Client *cli) {
  print_client(*cli);
}
