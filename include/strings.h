#ifndef GOAT_STRINGS_H
#define GOAT_STRINGS_H

#define strempty(s) ((s)[0] == '\0')

extern char *strtolower(char *s);
extern char *strtoupper(char *s);

extern char *strreverse(char *s);

#endif /* GOAT_STRINGS_H */
