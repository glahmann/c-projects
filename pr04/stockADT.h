#ifndef STOCK_H
#define STOCK_H

struct stock {
  char symbol[6];
  double price;
};

typedef struct stock Stock;

// Creates a stock struct.
// Pre:
// Post:
Stock createStock(char *symbol, double price);

// Returns the stock symbol of the given stock struct.
// Pre:
// Post: A pointer to a char array containing the stock symbol
char* getSymbol(Stock stockptr);

// Returns the price of the given stock struct.
// Pre:
// Post: A double representing the stock price
double getPrice(Stock stockptr);

// Sets the symbol for the given stock.
// Pre:
// Post: none
void setSymbol(Stock stockptr, char *theSymbol);

// Sets the price for the given stock.
// Pre:
// Post: none
void setPrice(Stock stockptr, double thePrice);

#endif
