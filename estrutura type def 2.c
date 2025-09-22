#include <stdio.h>
#include <math.h>

typedef struct { double x, y; } Ponto; //declaração de x e y como doubles e da estrutura "Ponto"->double


typedef struct { Ponto p1, p2; } Distancia;

double euclidiana(Distancia d) // o nome da funcao nao tem nada a ver com a estrutura
// o d poderia ser qualquer letra, ele é uma instância da estrutura
{
    double euclidiana = sqrt((d.p1.x-d.p2.x)*(d.p1.x-d.p2.x)+(d.p1.y-d.p2.y)*(d.p1.y-d.p2.y));//sqrt=raiz quadrada
    return euclidiana;
}

int main (){
    Distancia d; // d é uma instancia da Distancia
    d.p1.x=2; 
    d.p1.y=2; 
    d.p2.x=4; 
    d.p2.y=3; 
    printf("distancia = %.2f\n", euclidiana(d)); //printf com chamada de função
    }
