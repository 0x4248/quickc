#include <stdio.h>
#include <string.h>

void pass(char *string) { printf("\033[0;32m[PASS]\033[0m %s\n", string); }

int main() {
    printf("Hello, World!\n");
    pass("Hello, World!");
    return 0;
}