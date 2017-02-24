/*
 *  Test rational number ADT
 */

#include <stdio.h>
#include "rational.h"

int main(void) {
  Rational rat1, rat2, rat3;

  rat1 = create(1, 2);
  print(rat1);
  destroy(rat1);
  print(rat1);
  rat1 = create(1, 2);
  rat2 = create(1, 3);
  rat3 = multiply(rat1, rat2);  
  print(rat3);
  destroy(rat1);
  destroy(rat2);
  destroy(rat3);
}
