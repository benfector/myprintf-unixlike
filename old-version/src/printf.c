/* printf.c */
#include "printf.h"
#include <stdio.h>
#include <unistd.h>

void my_printf(const char *string, ...) {

    va_list args;
    va_start(args, string);

    char type;

    /* *string != '\0'. '\0' = FALSE. */
    while(*string) {

        if(*string == '%') {
            if(*(string+1) == '\0') {
                write(STDOUT, "%", SIZE);
                break;
            }

            type = *++string;
            Type t = data_type(type);

            if(t == T_INT) {
                int x = va_arg(args, int);
                int_to_char(x);
            } else if (t == T_FLOAT) {
                double f = va_arg(args, double);
                float_to_string(f);
            } else if (t == T_STRING) {
                char *str = va_arg(args, char*);

                if(str == NULL) {
                    write(STDOUT, "(null)", 6);
                } else {
                    while(*str) {
                        write(STDOUT, str, SIZE);
                        str++;
                    }
                }
            } else if (t == T_CHAR) {
                // char becomes int in va_arg.
                char c = va_arg(args, int);
                write(STDOUT, &c, SIZE);
            } else if (t == T_INVALID) {
                write(STDOUT, "%%", SIZE);
                write(STDOUT, &type, SIZE);
            }

            string++;
        }

        else if(*string == '\\') {
            char esc_char = *++string;
            escape_char(esc_char);
            string++;
            continue;
        }

        else {
            write(STDOUT, string, SIZE);
            string++; // advance pointer.
        }
    }

    va_end(args);
}

void test_myprintf(void);

int main(void) {
    test_myprintf();    
    return 0;
}

void test_myprintf(void) {
    // TEST 1: Basics
    printf("\n=== TEST 1: Basics ===\n");
    
    // Test 1.1: Simple string
    my_printf("{MYPRTF:}Hello World\n");
    printf("{PRINTF:}Hello World\n");
    
    // Test 1.2: %s
    my_printf("{MYPRTF:}%s\n", "Normal string");
    printf("{PRINTF:}%s\n", "Normal string");
    
    // Test 1.3: %c
    my_printf("{MYPRTF:}Char: %c\n", 'A');
    printf("{PRINTF:}Char: %c\n", 'A');
    
    // Test 1.4: Positive %d
    my_printf("{MYPRTF:}Int: %d\n", 42);
    printf("{PRINTF:}Int: %d\n", 42);
    
    // Test 1.5: Negative %d
    my_printf("{MYPRTF:}Negative: %d\n", -123);
    printf("{PRINTF:}Negative: %d\n", -123);
    
    // Test 1.6: Zero %d
    my_printf("{MYPRTF:}Zero: %d\n", 0);
    printf("{PRINTF:}Zero: %d\n", 0);
    
    // TEST 2: Multiple arguments
    printf("\n=== TEST 2: Multiple ===\n");
    
    my_printf("{MYPRTF:}%c %s %d\n", 'X', "text", 999);
    printf("{PRINTF:}%c %s %d\n", 'X', "text", 999);
    
    my_printf("{MYPRTF:}%d + %d = %d\n", 5, 3, 8);
    printf("{PRINTF:}%d + %d = %d\n", 5, 3, 8);
    
    my_printf("{MYPRTF:}%s: %c = %d points\n", "Letter", 'B', 85);
    printf("{PRINTF:}%s: %c = %d points\n", "Letter", 'B', 85);
    
    // TEST 3: Escapes
    printf("\n=== TEST 3: Escapes ===\n");
    
    my_printf("{MYPRTF:}New line\\n here\n");
    printf("{PRINTF:}New line\\n here\n\n");
    
    my_printf("{MYPRTF:}Tab\\t here\tend\n");
    printf("{PRINTF:}Tab\\t here\tend\n\n");
    
    my_printf("{MYPRTF:}Backspace\\b here\bend\n");
    printf("{PRINTF:}Backspace\\b here\bend\n\n");
    
    my_printf("{MYPRTF:}Quotes: \"text\"\n");
    printf("{PRINTF:}Quotes: \"text\"\n\n");
    
    my_printf("{MYPRTF:}Backslash: C:\\\\Users\\\\Name\n");
    printf("{PRINTF:}Backslash: C:\\\\Users\\\\Name\n\n");
    
    my_printf("{MYPRTF:}\\r test (carriage return)\rreplaces\n");
    printf("{PRINTF:}\\r test (carriage return)\rreplaces\n\n");

    // TEST 4: Complex strings
    printf("\n=== TEST 4: Strings ===\n");
    
    my_printf("{MYPRTF:}%s\n", "");
    printf("{PRINTF:}%s\n", "");
    
    my_printf("{MYPRTF:}%s\n", "a");
    printf("{PRINTF:}%s\n", "a\n");
    
    my_printf("{MYPRTF:}%s\n", "Hello\nWorld\tTab");
    printf("{PRINTF:}%s\n", "Hello\nWorld\tTab\n");
    
    my_printf("{MYPRTF:}Path: %s\n", "C:\\Program Files\\Test");
    printf("{PRINTF:}Path: %s\n", "C:\\Program Files\\Test\n");
    
    // TEST 5: Integer limits
    printf("\n=== TEST 5: Limits ===\n");
    
    my_printf("{MYPRTF:}INT_MAX: %d\n", 2147483647);
    printf("{PRINTF:}INT_MAX: %d\n", 2147483647);
    
    my_printf("{MYPRTF:}INT_MIN: %d\n", -2147483648);
    printf("{PRINTF:}INT_MIN: %d\n", -2147483648);
    
    my_printf("{MYPRTF:}Zero: %d\n", 0);
    printf("{PRINTF:}Zero: %d\n", 0);
    
    my_printf("{MYPRTF:}One: %d\n", 1);
    printf("{PRINTF:}One: %d\n", 1);
    
    my_printf("{MYPRTF:}Minus one: %d\n", -1);
    printf("{PRINTF:}Minus one: %d\n", -1);
    
    // TEST 6: Invalid format
    printf("\n=== TEST 6: Invalid ===\n");
    
    my_printf("{MYPRTF:}%z\n");
    printf("{PRINTF:}%z\n");
    
    my_printf("{MYPRTF:}Test %y text\n", 123);
    printf("{PRINTF:}Test %y text\n", 123);
    
    my_printf("{MYPRTF:}%\n");
    printf("{PRINTF:}%\n");
    
    my_printf("{MYPRTF:}%d % %d\n", 1, 2);
    printf("{PRINTF:}%d % %d\n", 1, 2);
    
    // TEST 7: Full mix
    printf("\n=== TEST 7: Mix ===\n");
    
    my_printf("{MYPRTF:}%c%c%c\n", 'A', 'B', 'C');
    printf("{PRINTF:}%c%c%c\n", 'A', 'B', 'C');
    
    my_printf("{MYPRTF:}%s%d%c\n", "Num", 42, '!');
    printf("{PRINTF:}%s%d%c\n", "Num", 42, '!');
    
    my_printf("{MYPRTF:}\\t before%c\\n after\n", 'X');
    printf("{PRINTF:}\\t before%c\\n after\n", 'X');
    
    // TEST 8: Special cases
    printf("\n=== TEST 8: Special ===\n");
    
    my_printf("{MYPRTF:}NULL string: %s\n", NULL);
    printf("{PRINTF:}NULL string: %s\n", NULL);
    
    my_printf("{MYPRTF:}Zero char: %c\n", '\0');
    printf("{PRINTF:}Zero char: %c\n", '\0');
    
    my_printf("{MYPRTF:}Tab\\tVisible\\tEnd\n");
    printf("{PRINTF:}Tab\\tVisible\\tEnd\n");
    
    my_printf("{MYPRTF:}Line1\\nLine2\\nLine3\n");
    printf("{PRINTF:}Line1\\nLine2\\nLine3\n");
    
    // TEST 9: Edge cases
    printf("\n=== TEST 9: Edge Cases ===\n");
    
    my_printf("{MYPRTF:}");
    printf("{PRINTF:}\n");
    
    my_printf("{MYPRTF:}\n");
    printf("{PRINTF:}\n");
    
    my_printf("{MYPRTF:}%d", 1000000);
    printf("{PRINTF:}%d\n", 1000000);
    
    my_printf("{MYPRTF:}%c%c%c\n", 65, 66, 67);
    printf("{PRINTF:}%c%c%c\n", 65, 66, 67);
    
    // TEST 10: Direct comparison
    printf("\n=== TEST 10: Comparison ===\n");
    
    const char *test_str = "test";
    my_printf("{MYPRTF:}my_printf: %d %c %s\n", 42, 'X', test_str);
    printf("{PRINTF:}printf: %d %c %s\n", 42, 'X', test_str);
    
    // TEST 11: Many arguments
    printf("\n=== TEST 11: Many args ===\n");
    
    my_printf("{MYPRTF:}%d %d %d %d %d\n", 1, 2, 3, 4, 5);
    printf("{PRINTF:}%d %d %d %d %d\n", 1, 2, 3, 4, 5);
    
    my_printf("{MYPRTF:}%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
    printf("{PRINTF:}%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
}
