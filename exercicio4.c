#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        return NULL;
    }
    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *inserir(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        return criarNo(valor);
    }
    if (valor < raiz->dado)
    {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if (valor > raiz->dado)
    {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void porNivel(No *raiz){
    if (raiz == NULL) return;
    

}