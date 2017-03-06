/**
 * Stock ADT
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stockADT.h"

Stock createStock(char *symbol, /*by value*/ double price) {

  Stock stockptr;
  strcpy(stockptr.symbol, symbol);
  stockptr.price = price;

  return stockptr;
}

void destroyStock(Stock stockptr) {
  //TODO deallocate memory (if symbol is dynamically allocated)
  free(&stockptr);
  //stockptr = NULL;
}

char* getSymbol(Stock stockptr) {
  char *output = malloc(sizeof(stockptr.symbol) + 1); // TODO free from call location
  strcpy(output, stockptr.symbol);
  return output;
}

double getPrice(Stock stockptr) {
  return stockptr.price;
}

void setSymbol(Stock stockptr, char *symbolptr) {
  strcpy(stockptr.symbol, symbolptr);
}

void setPrice(Stock stockptr, double thePrice) {
  stockptr.price = thePrice;
}
