/**
 * Stock ADT
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stockADT.h"

struct stock {
  char *symbol;
  double price;
};

Stock createStock(char *symbol, /*by value*/ double price) {

  Stock stockptr = malloc(sizeof(struct stock));
  if (stockptr != NULL) {                           // TODO Do I need this?
    stockptr->symbol = malloc(strlen(symbol) + 1); // Should malloc for max length?
    strcpy(stockptr->symbol, symbol);
    stockptr->price = price;
  }
  return stockptr;
}

void destroyStock(Stock stockptr) {
  //TODO deallocate memory
}

char* getSymbol(Stock stockptr) {
  return stockptr->symbol;
}

double getPrice(Stock stockptr) {
  return stockptr->price;
}

void setSymbol(char symbolptr) {

}

void setPrice(double thePrice) {

}
