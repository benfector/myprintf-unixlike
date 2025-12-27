#ifndef TYPE_H
#define TYPE_H

#include "../printf.h"

typedef enum { T_INT, T_FLOAT, T_LONG, T_CHAR, T_STRING, T_INVALID } Type;

Type data_type(char type_c);

#endif