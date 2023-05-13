#ifndef BASENAME_H
#define BASENAME_H

#include <stddef.h>

/* Return a static file name pointer that is a maximum of 256 bytes */
static inline char* basename(char* path) {
#ifdef _WIN32
    char divider = '\\';
#else
    char divider = '/';
#endif
    if (path == NULL || path[0] == '\0') {
        return NULL;
    }
    int length = 0;
    while (path[length] != '\0') {
        length++; // increment index until the end of string is reached
    }
    if (length == 0) {
        return NULL;
    }
    if (path[length-1] == divider) {
        return NULL;
    }
    int size = 0;
    for (int i = (length - 1); i > 0; i--) {
        if (path[i] == divider) {
            break;
            }
        size++;
    }
    static char name[256];
    int index = 0;
    for (int i = (length - size); i < length; i++) {
        name[index] = path[i];
        index++;
    }
    name[size] = '\0';
    return name;
}

#endif // BASENAME_H