#include<stdio.h>

int main (){
    char str [] = "mapear" ;
    char c = 'e';
    char * p = str ;
    int encontrado = 0;
    int posicao=0;
    while (*p!='\0'){
        if (*p==c){
            printf("caracter encontrado na posicao : %i", posicao+1);
            break;
        } 
            *p++;
            posicao++;
    }


}