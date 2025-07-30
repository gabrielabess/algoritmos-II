#include<stdio.h>
#include<string.h>

int main (){
    char palavra[50], palavra_inversa[50];
    int comprimento = 0, vogais = 0, consoantes = 0;
    printf("Digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0'; //remoção do caracter \0//
    comprimento=strlen(palavra);
    printf("A palavra digitada tem %d letras.\n", comprimento);
    for( int i=0; i<comprimento; i++){
        if( palavra[i]== 'a' || palavra[i]=='e' || palavra[i]=='i' || palavra[i]=='o' || palavra[i]=='u' ){
            vogais++;
            } else {
                consoantes++;
            }
    }
    printf("Número de consoantes: %d", consoantes);
    printf("\nNúmero de vogais: %d\n", vogais);
    
    int j=0;
    printf("Palavra invertida: ");
    for (int i= comprimento-1; i>=0; i--){
        printf("%c", palavra[i]);
        palavra_inversa[j]=palavra[i];
        j++;
    }
    palavra_inversa[j] = '\0';
    if (strcmp(palavra, palavra_inversa) == 0) {
        printf("\nÉ palíndromo!\n");
    } else {
        printf("\nNão é palíndromo!\n");
    }
}
