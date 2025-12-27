/* escape/escape.c */
#include "escape.h"

void escape_char(const char esc_char) {
    switch (esc_char) {
    case 'n': // line feed ("new line"). "\n".
        write(STDOUT, NEW_LINE, SIZE);
        break;
    case 'r': // carriage return.
        write(STDOUT, CARRIAGE_RETURN, SIZE);
        break;
    case '\\': // backslash (character).
        write(STDOUT, BACKSLASH, SIZE);
        break;    
    case '\"': // double quote
        write(STDOUT, ESCAPED_DOUBLE_QUOTE, SIZE);
        break;
    case '\'': // single quote
        write(STDOUT, SINGLE_QUOTE, SIZE);
        break;
    case 't': // tab.
        write(STDOUT, TAB , SIZE);
        break;
    case '0': // null character.
        write(STDOUT, NULL_CHARACTER, SIZE);
        break;
    case 'b': // backspace
        write(STDOUT, BACKSPACE, SIZE);
        break;
    default: // print the character as-is
        write(STDOUT, &esc_char, SIZE);
        break;
    }

}