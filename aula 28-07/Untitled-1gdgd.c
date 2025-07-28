#include<stdio.h>
#include<string.h>

int main (){
    char palavra[50];
    int comprimento, vogais, consoantes;
    printf("Digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    comprimento=strlen(palavra);
    for( int i=0; i<comprimento; i++){
        if( palavra[i]== 'a' || palavra[i]=='e' || palavra[i]=='i' || palavra[i]=='o' || palavra[i]=='u' ){
            vogais=+1;
            } else {
                consoantes=+1;
            }
    }
    printf("%d", consoantes);
    printf("%d", vogais);
}