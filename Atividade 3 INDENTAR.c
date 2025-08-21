#include<stdio.h>
int main () {
int array [] = {1 , 2 , 3 , 4, 5};
int tamanho = 5;
int arraycontra [5];
int *pFim = array + tamanho - 1;


for (int i = 0; i<tamanho; i++){
    arraycontra[i] = *pFim;
    pFim--;
}
 for(int i = 0; i < tamanho; i++){
    printf("%i", arraycontra[i]);
}
}
