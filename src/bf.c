#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "bf.h"

struct BFEngine bf_new(const size_t tape_len, const size_t cell_size,
        const size_t initial_pos) {

    struct BFEngine bf = {
        .tape = malloc(sizeof(size_t) * tape_len),
        .tape_len = tape_len,
        .cell_size = cell_size,
        .pos = initial_pos,
    };

    return bf;
}

void bf_free(const struct BFEngine *bf) {
    free(bf->tape);
}

bool is_valid_bf (const char *input) {
    size_t bracket_balance = 0;
    for (size_t i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
        case '[':
            bracket_balance++;
            break;
        case ']':
            bracket_balance--;
            break;
        }
    }
    return bracket_balance == 0;
}

size_t bf_exec (struct BFEngine *bf, const char *input, const size_t start_reading_at) {
    if (!is_valid_bf(input)) {
        fputs("ERROR: Your program has unbalanced brackets\n", stderr);
        return false;
    }

    for (size_t i = start_reading_at; input[i] != '\0'; i++) {
#ifdef DEBUG
    putchar(input[i]);
#endif
        switch (input[i]) {
        case '>':
            bf->pos = (bf->pos + 1) % bf->tape_len;
            break;

        case '<':
            bf->pos = ((bf->pos - 1 + bf->tape_len) % bf->tape_len);
            break;

        case '+':
            bf->tape[bf->pos] = (bf->tape[bf->pos] + 1) % bf->cell_size;
            break;

        case '-':
            bf->tape[bf->pos] = ((bf->tape[bf->pos] - 1 + bf->cell_size) % bf->cell_size);
            break;

        case '.':
            putchar(bf->tape[bf->pos]);
            break;

        case ',':
            bf->tape[bf->pos] = getchar();
            break;

        case '[':
            i = bf_exec(bf, input, i + 1);
            break;

        case ']':
            return bf->tape[bf->pos] == 0 ? i : bf_exec(bf,input, start_reading_at);
            break;
        }
    }

    return true;
}
