#include "str_util.h"

char *fgetall(FILE *fp) {
    size_t out_size = 1;
    char *out = malloc(sizeof(char) * out_size);
    int c;
    while ((c = fgetc(fp)) != EOF) {
        out[out_size - 1] = c;
        out = realloc(out, sizeof(char) * ++out_size);
    }
    out[out_size - 1] = '\0';
    return out;
}
