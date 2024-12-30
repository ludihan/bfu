#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "str_util.h"
#include "bf.h"

int main (int argc, char *argv[]) {
    if (argc > 1) {
        const char *fname = argv[1];
        FILE *fp = fopen(fname, "r");
        if (!fp) {
            perror("Could not open file");
            return EXIT_FAILURE;
        }
        char *out = fgetall(fp);
        BFEngine bf = bf_new(30000, 255, 0);
        bf_exec(&bf, out, 0);
        bf_free(&bf);
        free(out);
    }

    bool is_pipe = !isatty(fileno(stdin));
    if (is_pipe) {
        BFEngine bf = bf_new(30000, 255, 0);
        char *out = fgetall(stdin);
        bf_exec(&bf, out, 0);
        bf_free(&bf);
        free(out);
    }

    return EXIT_SUCCESS;
}
