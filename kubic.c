#define DEBUG 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#include <unistd.h>
#define wait(x) sleep(x)
#endif

#define KNEXT '>'
#define KPREV '<'
#define KADD '+'
#define KMIN '-'
#define KIN 'v'
#define KOUT '^'

#define KSTART '('
#define KEND ')'

#include "registry.h"

const char* numbers = "1234567890";

int numberify(const char* input_buffer, long start, long len) {
    int strlen = 0;
    char* res = malloc(255);
    for (int i = 0; i < 255; i++) {
        res[i] = 0;
    }

    int j = start;
    while (j <= len) {
        int passing = 0;
        for (int i = 0; i < 10; i++) {
            if (input_buffer[j] == numbers[i]) {
                res[strlen] = numbers[i];
                strlen++;
                passing = 1;
            }

            if (i == 9 && passing == 0) {
                return atoi(res);
            }
        }

        j++;
    }
    return atoi(res);
}

void parse(long start, const char* input_buffer, long len, registry* main_reg) {
    for (int i = start; i < len; i++) {
        //printf("%i %i", main_reg->size, main_reg->pointer);
        switch (input_buffer[i])
        {
        case KNEXT:
            mv_ptr(main_reg, 1);
            break;
        case KPREV:
            mv_ptr(main_reg, -1);
            break;
        case KADD:
            main_reg->registers[main_reg->pointer] += 1;
            break;
        case KMIN:
            main_reg->registers[main_reg->pointer] -= 1;
            break;
        case KOUT:
            printf("%c", main_reg->registers[main_reg->pointer]);
            break;
        case KSTART:
            ;
            long x = i;
            while (input_buffer[x] != KEND) {
                x++;
            }

            while (main_reg->registers[main_reg->pointer] > 0) {
                parse(i+1, input_buffer, x, main_reg);
            }

            break;
        case KIN:
            ;
            char input[255];
            gets(input);
            for (int j = main_reg->pointer; j <= strlen(input); j++) {
                printf("%i\n" ,main_reg->size);
                mv_ptr(main_reg, 1);
                main_reg->registers[main_reg->pointer] = input[j];
            }
            break;

        default:
            for (int j = 0; j < 10; j++) {
                if (numbers[j] == input_buffer[i]) {
                    int sel_num = numberify(input_buffer, i, len);
                    main_reg->registers[main_reg->pointer] = sel_num;
                    i += snprintf(0,0,"%+d",sel_num)-2;
                    break;
                }
            }
            break;
        }
    }
}

int main(int argc, char** argv) {
    FILE* source = fopen(argv[1], "r");

    fseek(source, 0, SEEK_END);
    long characters = ftell(source);
    fseek(source, 0, SEEK_SET);

    char* string_buffer = malloc(characters + 1);
    fread(string_buffer, 1, characters, source);
    fclose(source);

    string_buffer[characters] = 0;

    parse(0, string_buffer, characters, init_reg());
    return 0;
}
