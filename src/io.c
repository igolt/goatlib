#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "io.h"

int
eprintf(const char *fmt, ...)
{
    va_list ap;
    int result;

    va_start(ap, fmt);
    result = vfprintf(stderr, fmt, ap);
    va_end(ap);

    return result;
}

char *
fgetstr(char *s, int size, FILE *stream)
{
    if (fgets(s, size, stream)) {
        size_t len = strlen(s);

        if (len && s[len - 1] == '\n') {
            s[len - 1] = '\0';
        }
        return s;
    }
    return NULL;
}

char *
fgetword(char *word, int size, FILE *stream)
{
    int c;
    char *w = word;

    /* There is no space to fit anything in the string */
    if (size < 2) {
        return NULL;
    }

    while (isspace(c = getc(stream))) {
        /* Skip white spaces */;
    }

    if (c == EOF) {
        return NULL;
    }

    do {
        *w++ = c;
    } while (--size > 1 && (isalnum(c = getc(stream)) || c == '_'));
    if (size > 1 && c != EOF) {
        ungetc(c, stream);
    }
    *w = '\0';
    return word;
}
