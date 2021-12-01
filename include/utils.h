#ifndef GOAT_UTILS_H
#define GOAT_UTILS_H

#include <stdio.h>

#define MIN(a, b) ((a) < (b)) ? (a) : (b)
#define MAX(a, b) ((a) > (b)) ? (a) : (b)

#define ARRAYSIZE(a) (sizeof(a) / sizeof((a)[0]))

#define swap(type, a, b)                                                       \
    do {                                                                       \
        type *__aptr = &(a);                                                   \
        type *__bptr = &(b);                                                   \
        type __tmp   = (*__aptr);                                              \
                                                                               \
        (*__aptr) = (*__bptr);                                                 \
        (*__bptr) = __tmp;                                                     \
    } while (0)

#define PRINT_BYTE(byte)                                                       \
  printf("%c%c%c%c%c%c%c%c",                                                   \
          ((byte) & 0x80) ? '1' : '0',                                         \
          ((byte) & 0x40) ? '1' : '0',                                         \
          ((byte) & 0x20) ? '1' : '0',                                         \
          ((byte) & 0x10) ? '1' : '0',                                         \
          ((byte) & 0x08) ? '1' : '0',                                         \
          ((byte) & 0x04) ? '1' : '0',                                         \
          ((byte) & 0x02) ? '1' : '0',                                         \
          ((byte) & 0x01) ? '1' : '0')

#define PRINTBIN(x)                                                            \
    do {                                                                       \
        size_t __x_size        = sizeof(x);                                    \
        unsigned char *__x_ptr = (unsigned char *) &(x);                       \
                                                                               \
        for (;;) {                                                             \
            unsigned char __byte = __x_ptr[--__x_size];                        \
                                                                               \
            PRINT_BYTE(__byte);                                                \
            if (__x_size == 0) {                                               \
                break;                                                         \
            }                                                                  \
            putchar(' ');                                                      \
        };                                                                     \
    } while (0)

#endif /* GOAT_UTILS_H */
