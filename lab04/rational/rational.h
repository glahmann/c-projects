#ifndef RATIONAL_H
#define RATIONAL_H

typedef struct rational* Rational;

Rational create(int n, int d);
void destroy(Rational a);
Rational multiply(Rational a, Rational b);
void print(Rational rat);

#endif
