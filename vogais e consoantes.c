#include<stdio.h>
#include<string.h>

int main (){
    char palavra[50];
    int comprimento, vogais = 0, consoantes = 0;
    printf("Digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    comprimento=strlen(palavra);
    printf("%d\n", comprimento);
    for( int i=0; i<comprimento; i++){
        if( palavra[i]== 'a' || palavra[i]=='e' || palavra[i]=='i' || palavra[i]=='o' || palavra[i]=='u' ){
            vogais++;
            } else {
                consoantes++;
            }
    }
    printf(" %d", consoantes);
    printf(" %d", vogais);
}
