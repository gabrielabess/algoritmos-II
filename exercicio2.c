#include<stdio.h>
#include<stdlib.h>

typedef struct No {
int dado;
struct No *esq;
struct No *dir;
} No;


No* criarNo(int valor) {
No *novo = (No*) malloc(sizeof(No));
if (novo == NULL) {
return NULL;
}
novo->dado = valor;
novo->esq = NULL;
novo->dir = NULL;
return novo;
}


No* inserir(No *raiz, int valor) {
if (raiz == NULL) {
return criarNo(valor);
}
if (valor < raiz->dado) {
raiz->esq = inserir(raiz->esq, valor);
} else if (valor > raiz->dado) {
raiz->dir = inserir(raiz->dir, valor);
}
return raiz;
}

int altura(No *raiz) {
    if (raiz == NULL) return 0;

    int esq = altura(raiz->esq);
    int dir = altura(raiz->dir);

    return 1 + (esq > dir ? esq : dir);
}

int contarNos(No *raiz) {
    if (raiz == NULL) return 0;

    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

int somarNos (No *raiz){
    if (raiz == NULL) return 0;

    return raiz->dado + somarNos(raiz->esq) + somarNos(raiz->dir);
}

int main() {
No *raiz = NULL;
No *resultado;

raiz = inserir(raiz, 8);
raiz = inserir(raiz, 3);
raiz = inserir(raiz, 10);
raiz = inserir(raiz, 1);
raiz = inserir(raiz, 14);
raiz = inserir(raiz, 6);



printf("Altura: %d", altura(raiz));
printf("\nContar nós: %d", contarNos(raiz));
printf("\nSoma: %d", somarNos(raiz));

}