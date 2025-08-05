#include <stdio.h>
#define MAX 10
#define VERBOSE

int main()
{
    int arr[MAX] = {2, 4, 6, 8}; // 4 elementos ordenados
    int n = 4;                   // n elementos
    int newValue = 5;            // teste com insercoes centrais

    int i;
    for (i = 0; i < n; i++)
    { // 0,1,2,3 o i é 2
        if (arr[i] > newValue)
        {
#ifdef VERBOSE
            printf("SAÍDAS NA DEFINIÇÃO DO I\ni: %d, arr[i]: %d\n", i, arr[i]);
#endif
            break;
        }
    }
    for (int j = n; j >= i; j--)
    { // 4,3,2
#ifdef VERBOSE
        printf("Vezes que os números são avançados uma posição para que o novo número seja inserido (esse processo ocorre do maior para o menor): %d\n", i);
#endif                       
        arr[j + 1] = arr[j]; // j4=j5 atribuindo valor
    }
    arr[i] = newValue; // a posição definida anteriormente, que já foi esvaziada em outros processos, recebe o novo valor
    n++;

    for (int k = 0; k < n; k++)
    {
    // aqui acontece o output do array (0,1,2,3) com o novo valor já inserido
            printf("K = %d\nElemento do arr= %d\n", k, arr[k]);
    }
    printf("\n");

    return 0;
}