# Basename

A header only library for parsing file names out of paths.
Cross-platform, static linking with no compile flags required.

### Usage
```C
// main.c
#include "basename.h"
#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void) {
	char* path = "/home/user/Pictures/Screenshots/image.png";
	char* name = basename(path);
    if (name == NULL) {
        return EXIT_FAILURE;
    }
    printf("The file name is: %s\n", name);
    return EXIT_SUCCESS;
}

// gcc main.c -o main.o
```
