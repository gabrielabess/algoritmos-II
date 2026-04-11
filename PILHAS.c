#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int dado;
    struct No *prox;
}No;

typedef struct {
    No *topo; //só aponta para o topo
}Pilha;

void inicializarPilha(Pilha *p){
    p->topo=NULL; // só tem o parametro topo para inicializar
}


int pilhaVazia(Pilha *p){
    return p->topo == NULL;  //se o topo for null retorna 1, se tiver retorna 0
}

int push(Pilha *p, int valor){
    No *novo = (No *)malloc(sizeof(No));

    if(novo==NULL){
        return 0; //verificação se a alocação funcionou
    }


    novo->dado = valor; //recebe o valor
    novo->prox = p->topo; //o novo no aponta para o antigo topo
    p->topo = novo; //o topo é o novo no


    return 1;
}

int pop(Pilha *p, int *valor){
    if(p->topo == NULL){
        return 0;
    }

    No *temp = p->topo;
    *valor = temp->dado;
    p->topo = temp;
    free(temp);

    return 1;
}

int peek(Pilha *p, int *valor){
    if(p->topo == NULL){
        return 0;
    }

    *valor = p->topo->dado;
    return 1;
}

void mostrarPilha(Pilha *p){
    No *atual = p->topo;
    if(atual == NULL){
        printf("PILHA VAZIA!");
        return;
    }

    printf("TOPO -> ");
    while (atual != NULL){
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }

    printf("NULL\n");
}

void liberarPilha(Pilha *p){
    No *atual = p->topo;
    No *temp;

    while(atual!=NULL){
        temp=atual;
        atual=atual->prox;
        free(temp);
    }

    p->topo = NULL;
}

int main(){
    Pilha p;
    int opcao, valor;

    inicializarPilha(&p);

    do{
        printf("\n========Menu Pilha========\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Consultar topo\n");
        printf("4. Mostrar pilha\n");
        printf("5. Verificar Lista\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf(" %d", &opcao);

        switch(opcao){
            case 1: {
                printf("Digite o valor: ");
                scanf(" %d", &valor);

                if(push(&p, valor)){
                    printf("Valor empilhado com sucesso!");
                }
                else {
                    printf("Erro ao alocar memória!");
                }
            }
            break;
            case 2: {
                if(pop(&p, &valor)){
                    printf("Valor removido: %d\n", valor);
                }
                else {
                    printf("Pilha vazia!");
                }
            }
            break;
            case 3: {
                if(peek(&p, &valor)){
                    printf("Topo da pilha: %d\n", valor);
                }
                else {
                    printf("Pilha vazia!");
                }
            }
            break;
            case 4: {
                mostrarPilha(&p);
            }
            break;
            case 5: {
                if(pilhaVazia(&p)){
                    printf("A pilha está vazia!");
                } else {
                    printf("A pilha não está vazia!");
                }

            }
            break;
            case 0: {
                printf("Encerrando...\n");
            }
            break;
            default:
            printf("Opção inválida!");
            break;
        }
    }while(opcao!=0);

    liberarPilha(&p);
    return 0;
}
