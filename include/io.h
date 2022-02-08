#ifndef GOAT_IOLIB_H
#define GOAT_IOLIB_H

#include <stdio.h>

#define print(s) fputs(s, stdout)

#define eprint(s) fputs(s, stderr)

#define eputs(msg) fprintf(stderr, "%s\n", (msg));
extern int eprintf(const char *fmt, ...);

extern char *fgetstr(char *s, int size, FILE *stream);
#define getstr(s, size) fgetstr(s, size, stdin)

extern char *fgetword(char *s, int size, FILE *stream);
#define getword(s, size) fgetword(s, size, stdin)

#endif /* GOAT_IOLIB_H */
