#include <stdio.h>
#include <stdlib.h>

int *somaArrays(int *array1, int *array2, int tamanho) {
    int *resultado = (int *) malloc(tamanho * sizeof(int));
    if (resultado == NULL) {
        return NULL;
    }
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = array1[i] + array2[i];
    }
    return resultado;
}

int main() {
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {10, 20, 30, 40, 50};
    int tamanho = 5;

    int *soma = somaArrays(array1, array2, tamanho);

    if (soma != NULL) {
        printf("Resultado da soma dos arrays:\n");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", soma[i]);
        }
        printf("\n");
        free(soma);
    }
}
