/**
 * Driver for Project 4
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientADT.h"
#include "listADTgen.h"
#include "stockADT.h"

// Compares the equality relationship between a and b.
// pre:
// post: an integer representing the equality relation between a and b
int compare(const void *a, const void *b);

// Frees the memory allocation for client structs.
// pre: *d points to a valid memory location for a client object
// post: none
void destroyItem(void *d);

//
// pre: *d points to a valid memory location for a client object
// post: none
void printItem(void *d);

// Reads info from client file and builds a list of client objects.
// pre:
// post: none
void readClients(FILE *fptr, ListType clientList);

// Reads info from stock file and builds a list of stock objects.
// pre:
// post: none
void readStocks(FILE *fptr, ListType stockList);

//
// pre:
// post:
void readTXT();


int main(void) {
  FILE *fptrClients;
  FILE *fptrStocks;
  FILE *fptrStCl;
  FILE *fptrSummary;
  ListType clientList, stockList;

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

  //sort_list(clientList);
  print_list(clientList, printItem);

  // Close all files
  fclose(fptrClients);
  fclose(fptrStocks);
  fclose(fptrStCl);
  fclose(fptrSummary);

  // Free lists
  //clear_list(clientList, destroyItem); // TODO free memory from clients
  make_empty(stockList);
  destroy_list(clientList);
  destroy_list(stockList);
}

void readClients(FILE *fptr,/*Pass by reference*/ ListType clientList) {
  int i = 0, idNum;
  char last[20], name[40], email[40], phone[15], line[95];
  if (fptr == NULL) {
    fputs("Client file not found!", stderr);
    exit(-1);
  } else {
    while (fgets(line, 95, fptr) != NULL) {
      sscanf(line, "%d ", &idNum);
      fgets(line, 40, fptr);
      sscanf(line, "%s %s", name, last);
      strcat(name, last);
      fgets(line, 40, fptr);
      sscanf(line, "%s", email);
      fgets(line, 15, fptr);
      sscanf(line, "%s", phone);

      // create a client object
      Client curr = createClient(idNum, name, email, phone);
      // add client object pointer to list
      push(clientList, curr);
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
    fgets(line, 95, fptr); // Skip labels in first line
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
  int c = ((Client) a)->idNum;
  int d = ((Client) b)->idNum;

  return (c - d);
}

void printItem(void *d) {
  print_client(((Client) d));
}

void destroyItem(void *d) {
  destroy_client(((Client) d));
}
