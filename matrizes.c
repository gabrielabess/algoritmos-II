#include<stdio.h>

int main (){
    int matriz1[3][3], matriz2[3][3], matrizsoma[3][3], matrizsub[3][3], matrizmult[3][3], opcao;
   
    printf("Seja Bem-vindo! Vamos definir sua primeira matriz: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("Insira o termo [%d][%d]: ", i+1, j+1);
            scanf(" %d", &matriz1[i][j]);
        }
    }
    
    printf("Confira sua 1° matriz: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("[%d]", matriz1[i][j]);
        }printf("\n");
    }
    
    printf("Vamos definir sua segunda matriz: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("Insira o termo [%d][%d]: ", i+1, j+1);
            scanf(" %d", &matriz2[i][j]);
        }
    }
    
    printf("Confira sua 2° matriz: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("[%d]", matriz2[i][j]);
        }printf("\n");
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
           matrizsoma[i][j]=matriz1[i][j]+matriz2[i][j];
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
           matrizsub[i][j]=matriz1[i][j]-matriz2[i][j];
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
           matrizmult[i][j]=matriz1[i][j]*matriz2[i][j];
        }
    }
    
    printf("Confira a matriz da soma: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("[%d]", matrizsoma[i][j]);
        }printf("\n");
    }
    
    printf("Confira a matriz de subtração: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("[%d]", matrizsub[i][j]);
        }printf("\n");
    }
    
    printf("Confira a matriz de multiplicação: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("[%d]", matrizmult[i][j]);
        }printf("\n");
    }
    printf("\nOperações concluídas!!");
}
