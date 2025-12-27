#ifndef PRINTF_H
#define PRINTF_H

/* libs */
#include <unistd.h> // system call 'write()'.
#include <stdarg.h> /* works with variadic functions (functions with a variable number of arguments).

Type: va_list → stores the list of variadic arguments.

Macros:

va_start() → initializes the argument list.

va_arg() → accesses the next argument.

va_end() → cleans up/terminates the use of the list.

va_copy() (C99) → makes a copy of the list.

*/


/* local header. */
#include "escape/escape.h"
#include "types/int.h"
#include "types/float.h"
#include "types/type.h"

#define STDOUT 1


void my_printf(const char *string, ...);

#endif