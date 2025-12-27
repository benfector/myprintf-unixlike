/* types/float.c */

#include "float.h"

// i used 'snprintf' because implementing the float type from scratch would be
// too complicated.
void float_to_string(double n) {
  char buffer[60];
  snprintf(buffer, sizeof(buffer), "%.2f", n);

  int i = 0;
  while (buffer[i]) {
    write(STDOUT, &buffer[i], 1);
    i++;
  }
}