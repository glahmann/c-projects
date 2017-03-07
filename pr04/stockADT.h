#ifndef STOCK_H
#define STOCK_H

struct stock {
  char symbol[6];
  double price;
};

typedef struct stock Stock;

//
// Pre:
// Post:
Stock createStock(char *symbol, double price);

//
// Pre:
// Post:
//void destroyStock(Stock stockptr);

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
void setSymbol(Stock stockptr, char *theSymbol);

//
// Pre:
// Post:
void setPrice(Stock stockptr, double thePrice);

#endif
