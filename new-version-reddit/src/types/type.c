/* types/types.c */

#include "type.h"

Type data_type(char type_c) {
  switch (type_c) {
    case 'd':
      return T_INT;
    case 's':
      return T_STRING;
    case 'c':
      return T_CHAR;
    case 'f':
      return T_FLOAT;
    default:
      return T_INVALID;
  }
}