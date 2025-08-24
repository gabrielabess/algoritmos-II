#include <stdio.h>

void buscaValor(int *array, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == valor) {
            printf("Numero %d encontrado na posicao %d do array.\n", valor, i);
            return; // encerra a função depois de achar
        }
    }
    printf("Numero %d nao foi encontrado no array.\n", valor);
}

int main() {
    int array1[] = {1, 2, 3, 4, 5};
    int tamanho = 5;
    int valor;

    printf("Digite o valor que deseja buscar no array: ");
    scanf("%i", &valor);

    buscaValor(array1, tamanho, valor);
}
