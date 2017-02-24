
#include <stdio.h>
#include "listADT.h"

int main(void)
{
  ListType l1, l2;
  
  l1 = create();
  l2 = create();
  int n = 999;
  
  int i, j;

  for (i = 1; i <= 10; i++) {
	push(l1, i );
	
  }

  printl(l1);

  delete(l1, 3);
  printl(l1);
  push(l2, n);
  push(l2, n);
  push(l2, n);
  printl(l2);

  destroy(l1);

  make_empty(l2);
  if (is_empty(l2))
    printf("l2 is empty\n");
  else
    printf("l2 is not empty\n");

  destroy(l2);

  return 0;
}
