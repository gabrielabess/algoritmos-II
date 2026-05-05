#include <stdio.h>
#include <stdlib.h>

typedef struct Produto
{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
    struct No *esq;
    struct No *dir;
} Produto;

Produto *cadastrarProduto(int valor, int codigo, char nome, float preco, int quantidade)
{
    Produto *novo = (Produto *)malloc(sizeof(Produto));
    if (novo == NULL)
    {
        return NULL;
    }

    novo->codigo = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    printf("Insira os seguintes dados:");
    printf("\nNome: ");
    fgets(nome, 50, stdin);
    printf("\nPreço: ");
    scanf(" %f", preco);
    printf("\nQuantidade: ");
    scanf(" %d", quantidade);
    return novo;
}

Produto *inserir(Produto *raiz, int codigo, int valor)
{
    if (raiz == NULL)
    {
        return criarNo(codigo); // local onde a inserção ocorre de fato
    }

    // inserir funcao buscar para caso o produto ja exista
    if (buscar(raiz, valor) != 0)
    {
        printf("Produto já cadastrado!");
        return;
    }

    if (valor < raiz->codigo)
    {                                                  // caso o valor seja menor que o nó
        raiz->esq = inserir(raiz->esq, codigo, valor); // a raiz se torna o filho a esquerda (menor) e a função é chamada novamente
    }
    else if (valor > raiz->codigo)
    {                                                  // caso o valor seja maior que o nó
        raiz->dir = inserir(raiz->dir, codigo, valor); // a raiz se torna o filho a direita (maior) e a função é chamada novamente
    }

    return raiz;
}

Produto *buscar(Produto *raiz, int valor)
{
    if (raiz == NULL)
    {
        return raiz;
    }

    if (raiz->codigo == valor)
    {
        printf("==PRODUTO ENCONTRADO==");
        printf("\nCódigo: %d", raiz->codigo);
        printf("\nNome: %s", raiz->nome);
        printf("\nPreço: %.2f", raiz->preco);
        printf("\nQuantidade: %d", raiz->quantidade);
        printf("\nValor total do produto: %.2f", raiz->preco * raiz->quantidade);
    }

    if (valor < raiz->codigo)
    {
        return buscar(raiz->esq, valor);
    }
    else
    {
        return buscar(raiz->dir, valor);
    }

    printf("Valor não encontrado!");
    return;
}

void emOrdem(Produto *raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esq);
        printf("Código: %d", raiz->codigo);
        printf("Nome: %s", raiz->nome);
        emOrdem(raiz->dir);
    }
}

int contarProdutos(Produto *raiz)
{
    if (raiz == NULL)
        return 0;

    return 1 + contarProdutos(raiz->esq) + contarProdutos(raiz->dir);
}

float calcularEstoque(Produto *raiz)
{
    if (raiz == NULL)
        return 0;
    return (raiz->preco * raiz->quantidade) + calcularEstoque(raiz->esq) + calcularEstoque(raiz->dir);
}

Produto *menorPreco(Produto *raiz)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    Produto *menor = raiz;

    Produto *esq = menorPreco(raiz->esq);
    if (esq != NULL && esq->preco < menor->preco) {
        menor = esq;
    }

    Produto *dir = menorPreco(raiz->dir);
    if (dir != NULL && dir->preco < menor->preco) {
        menor = dir;
    }

    return menor;
}

Produto *maiorPreco(Produto *raiz)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    Produto *maior = raiz;

    Produto *dir = maiorPreco(raiz->dir);
    if (dir != NULL && dir->preco > maior->preco) {
        maior = dir;
    }

    Produto *esq = maiorPreco(raiz->esq);
    if (esq != NULL && esq->preco > maior->preco) {
        maior = esq;
    }

    return maior;
}

int main()
{
}

//falta funcao remocao, listar por nível e menu. Boa sorte;)
