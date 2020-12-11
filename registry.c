#include "registry.h"
#include <stdio.h>

registry* init_reg() {
    registry* reg = malloc(sizeof(registry));
    reg->pointer = 0;
    reg->size = 1;
    reg->registers = malloc(sizeof(int) * reg->size);
    reg->registers[0] = 0;

    return reg;
}

void mv_ptr(registry* reg, int relative_pos) {
    if (reg->pointer + relative_pos > reg->size) {
        reg->size += relative_pos + 1;
        reg->pointer += relative_pos;

        int* new_registers = realloc(reg->registers, sizeof(int) * reg->size);
        new_registers[reg->pointer] = 0;

        reg->registers = new_registers;
        return;
    } else if (reg->pointer + relative_pos < 0) {
        return;
    } else {
        reg->pointer += relative_pos;
    }
}
