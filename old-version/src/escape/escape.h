#ifndef ESCAPE_H
#define ESCAPE_H

#include "../printf.h"

/*

    \n = 10 (0x0A)              \t = 9 (0x09)
    \r = 13 (0x0D)              \0 = 0 (0x00)
    \\ = 92 (0x5C)              \" = 34 (0x22)
    \b = 8 (0x08)

*/

/* escape characters */
#define NEW_LINE "\x0A"
#define CARRIAGE_RETURN "\x0D"
#define BACKSLASH "\x5c"
#define TAB "\x09"
#define NULL_CHARACTER "\x00"
#define ESCAPED_DOUBLE_QUOTE "\""
#define SINGLE_QUOTE "'"
#define BACKSPACE "\x08"

#define SIZE 1

/* function */
void escape_char(const char esc_char);

#endif