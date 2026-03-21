#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "generator.h"
#include "utils.h"

int generate_brainfuck(const char* text) {
    int tape[5] = {0, 30, 70, 100, 110};
    int pointer = 0;

    multiply(10, '+');
    putchar('[');
    putchar('>'); multiply(3, '+'); 
    putchar('>'); multiply(7, '+');
    putchar('>'); multiply(10, '+');
    putchar('>'); multiply(11, '+');
    multiply(4, '<'); putchar('-');  
    putchar(']');
    putchar('\n');

    for (int i = 0; text[i]; ++i) {
        int target = text[i];
        int best_cell = 0;
        int min_cost = 9999;

        for (int c = 0; c < 5; c++) {
            int pointer_moves = abs(pointer - c);
            int value_changes = abs(tape[c] - target);
            int total_cost = pointer_moves + value_changes;

            if (total_cost < min_cost) {
                min_cost = total_cost;
                best_cell = c;
            }
        }

        if (pointer < best_cell) {
            multiply(best_cell - pointer, '>');
        } else if (pointer > best_cell) {
            multiply(pointer - best_cell, '<');
        }
        pointer = best_cell; 

        int diff = target - tape[pointer];
        if (diff > 0) {
            multiply(diff, '+');
        } else if (diff < 0) {
            multiply(-diff, '-');
        }

        putchar('.');
        putchar('\n');

        tape[pointer] = target;
    }

    return 0;
}