#include "strings.h"
#include "utils.h"

#include <ctype.h>
#include <string.h>

#define BOILER_PLATE(func)                                                     \
    do {                                                                       \
        char *it = s;                                                          \
                                                                               \
        for (it = s; *it; ++it) {                                              \
            *it = func(*it);                                                   \
        }                                                                      \
        return s;                                                              \
    } while (0)

char *
strtolower(char *s)
{
    BOILER_PLATE(tolower);
}

char *
strtoupper(char *s)
{
    BOILER_PLATE(toupper);
}

#undef BOILER_PLATE

char *
strreverse(char *s)
{
    if (!strempty(s) && s[1]) {
        char *begin = s;
        char *end   = s + strlen(s);

        while (begin < --end) {
            swap(char, *begin, *end);
            ++begin;
        }
    }
    return s;
}
