#ifndef STRUTIL_H
#define STRUTIL_H

#include <stdio.h>
#include <stdlib.h>

// Reads everything from a given FILE and returns the string sequence
// Needs to be free'd manually
extern char *fgetall(FILE *fp);

#endif /* STRUTIL_H */
