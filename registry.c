#include "registry.h"

registry* init_reg() {
    registry* reg = malloc(sizeof(registry));
    reg->pointer = 0;
    reg->size = 0;
    reg->registers = malloc(reg->size);
    reg->registers[0] = 0;

    return reg;
}

void mv_ptr(registry* reg, int relative_pos) {
    if (reg->pointer + relative_pos > reg->size) {
        reg->size += relative_pos;
        reg->pointer += relative_pos;
        reg->registers = realloc(reg->registers, reg->size);
        reg->registers[reg->size] = 0;
    } else {
        reg->pointer += relative_pos;
    }
}
