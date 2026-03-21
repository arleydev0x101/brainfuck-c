#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "utils.h"

int run_brainfuck(const char* code, int print_decimal, char separator) {
    unsigned char* cells = (unsigned char*)calloc(MAX_CELLS, sizeof(unsigned char));
    if (cells == NULL) {
        puts(MEM_ERROR_MSG);
        return 1;
    }

    int stack_loop[100];
    int stack_i = -1;
    size_t x = 0;
    size_t input_len = strlen(code);

    for (size_t i = 0; i < input_len; ++i) {
        switch (code[i]) {
            case '>':
                x = (x + 1) % MAX_CELLS;
                break;
            case '<':
                x = (x == 0) ? MAX_CELLS - 1 : x - 1;
                break;
            case '+':   
                cells[x] += 1;  
                break;
            case '-':   
                cells[x] -= 1;  
                break;
            case '[':
                if (cells[x] == 0) {
                    int opbr = 1;
                    while (opbr > 0 && i + 1 < input_len) {
                        i++;
                        if (code[i] == '[') opbr++;
                        else if (code[i] == ']') opbr--;
                    }
                } else {
                    stack_loop[++stack_i] = i;
                }
                break;
            case ',':
                scanf("%c", &cells[x]);
                break;
            case ']':
                if (cells[x] != 0)
                    i = stack_loop[stack_i];
                else
                    --stack_i;
                break;
            case '.':
                if (print_decimal) {
                    printf("%d", cells[x]);
                    if ((i + 3) < input_len)
                        printf("%c", separator);
                } else {
                    putchar(cells[x]);
                }
                break;
        }
    }
    
    free(cells);
    return 0;
}