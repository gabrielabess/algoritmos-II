#include<stdio.h>

int main (){
    int matriz [3][3]={ {1 , 2 , 3} ,{4 , 5 , 6} ,{7 , 8 , 9} };
    int soma=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            soma+=matriz[i][j];
        }
    } printf("Soma de maneira tradicional:%i", soma);
    int soma2=0;
    int *p=matriz[0];
    for ( int i=0;i<9;i++){
        soma2+=*(p+i);  //aqui o endereço do ponteiro inicia no zero e vai somando até chegar no 9 (ultimo elemento)
    }
    printf("\nSoma ponteiro; %i", soma2);
    }
