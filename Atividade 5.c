#include <stdio.h>

void troca(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a1 = 3;
    int b1 = 4;
    int *a = &a1;
    int *b = &b1;

    printf("a: %i  b: %i\n", *a, *b);
    troca(a, b);
    printf("Após troca!\na: %i  b: %i\n", *a, *b);
}
