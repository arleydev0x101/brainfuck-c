#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

#define MEM_ERROR_MSG "Memory allocation error!\nPlease, free your memory to use this program, properly."
#define MAX_CELLS 30000

void multiply(int n, char c);

char* get_safe_input(void);

#endif 