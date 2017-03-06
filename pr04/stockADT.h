#ifndef STOCK_H
#define STOCK_H

typedef struct stock *Stock;

//
// Pre:
// Post:
Stock createStock(char *symbol, double price);

//
// Pre:
// Post:
void destroyStock(Stock stockptr);

//
// Pre:
// Post:
char* getSymbol();

//
// Pre:
// Post:
double getPrice();

//
// Pre:
// Post:
void setSymbol(char theSymbol);

//
// Pre:
// Post:
void setPrice(double thePrice);

#endif
