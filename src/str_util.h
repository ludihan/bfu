#ifndef STRUTIL_H
#define STRUTIL_H

// Reads eveything from a given FILE(from stdio) and returns the string sequence
// Needs to be free'd manually
extern char *fgetall(FILE *fp);

#endif /* STRUTIL_H */
