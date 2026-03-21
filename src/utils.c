#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void multiply(int n, char c)
{
    for (int i = 0; i < n; ++i)
    {
        putchar(c);
    }
}

char *get_safe_input(void)
{
    size_t i_limit = MAX_CELLS;
    char *input = (char *)malloc(i_limit * sizeof(char));

    if (input == NULL)
    {
        puts(MEM_ERROR_MSG);
        return NULL;
    }

    int c;
    size_t i = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (i + 1 >= i_limit)
        {
            i_limit += MAX_CELLS;
            char *tmp = (char *)realloc(input, i_limit);
            if (tmp == NULL)
            {
                puts(MEM_ERROR_MSG);
                free(input);
                return NULL;
            }
            input = tmp;
        }
        input[i++] = (char)c;
    }
    input[i] = '\0';

    return input;
}