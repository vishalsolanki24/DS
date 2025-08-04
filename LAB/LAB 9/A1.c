#include <stdio.h>
#include <stdlib.h>

void  main() {
    int *i = (int*)malloc(sizeof(int));
    char *c = (char*)malloc(sizeof(char));
    float *f = (float*)malloc(sizeof(float));

    *i = 25;
    *c = 'A';
    *f = 3.14;

    printf("Integer: %d\nCharacter: %c\nFloat: %.2f\n", *i, *c, *f);

    free(i);
    free(c);
    free(f);

}
