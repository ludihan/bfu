#ifndef BF_H
#define BF_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct BFEngine {
    char *tape;
    size_t tape_len;
    size_t cell_size;
    size_t pos;
} BFEngine;

extern struct BFEngine bf_new(const size_t tape_len, const size_t cell_size, 
        const size_t initial_pos);

extern void bf_free(const struct BFEngine *bf);

// Verifies if the given input is a valid bf program
// Return true if it's valid, false otherwise
extern bool is_valid_bf (const char *input);

// Executes the given input, taking control of stdin and stdout
// Verifies the program first by using is_valid_bf
// Returns the value from is_valid_bf
extern size_t bf_exec (struct BFEngine *bf, const char *input, 
        const size_t start_reading_at);

// Compiles a program to ELF(linux) (not yet programmed)
// I don't think i'll be able to actually make this function work but who knows
// extern void bf_compile (struct BFEngine *bf, const char *input,
//       const char *output_file_name);

#endif /* BF_H */
