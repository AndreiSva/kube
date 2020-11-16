#include <stdlib.h>
#include <stdio.h>

typedef struct registry {
    int* registers;
    long pointer;
    long size;
} registry;

registry* init_reg();
void mv_ptr(registry* reg, int relative_pos);