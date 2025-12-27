/* types/int.c */
#include "int.h"

void int_to_char(int n) {
  char buffer[30];
  int i = 0;
  if (n == 0) {
    write(STDOUT, "0", 1);
    return;
  }

  /* Deals with INT_MIN */
  if (n == -2147483648) {
    write(STDOUT, "-2147483648", 11);
    return;
  }

  if (n < 0) {
    write(STDOUT, "-", 1);
    n = -n;
  }

  while (n > 0) {
    buffer[i++] = (n % 10) + '0';
    n /= 10;
  }

  while (i > 0) {
    write(STDOUT, &buffer[--i], 1);
  }
}
