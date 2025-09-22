#include <stdio.h>
#include <math.h> // fabs

typedef struct { double x, y; } Ponto; //declaração de x e y como doubles e da estrutura "Ponto"->double


typedef struct { Ponto p1, p2; } Retangulo; // definicao da estrutura retangulo declaração de mais dois "Ponto" 
//p1 e p2, dentro deles tem o x e y pq o retangulo é declarado na segunda parte da estrutura
// importancia:
// Retangulo = p1 e p2
//cada um recebe dois doubles (x e y)
double area_retangulo(Retangulo r) // declaração da funcao para calculo da area do retangulo R
{
    double largura = fabs(r.p2.x - r.p1.x); // delta da distancia dos pontos 
    double altura = fabs(r.p2.y - r.p1.y);
    return largura * altura;
}

int main (){
    Retangulo r; // declaração do retangulo r que tem a struct já declarada lá em cima
    r.p1.x=2; //r-> retangulo
    r.p1.y=2; //p1 e p2-> pontos
    r.p2.x=4; //x e y os pontos recebem de heranca
    r.p2.y=3; //declaração feita com o endereço completo
    printf("Área = %.2f\n", area_retangulo(r)); //printf com chamada de função
}
