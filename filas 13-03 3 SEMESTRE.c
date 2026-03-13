#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int valor;
    struct Node *next;
} Node;

typedef struct Fila{
        struct Node *front;
        struct Node *rear;
}Fila;


void inicializar(Fila *f /*int valor*/){
    f->front = NULL;
    f->rear = NULL;
}

void inserirFim(Fila *f, int valor) {
Node *novo = (Node*)malloc(sizeof(struct Node)); // cria novo nó
if(novo == NULL) { // verifica erro de memória
printf("Erro de alocacao\n");
return;
}
novo->valor = valor; // armazena valor
novo->next = NULL; // será o último elemento
if(f->rear == NULL) { // fila vazia
f->front = novo; // novo nó vira o primeiro
f->rear = novo; // e também o último
return;
}
f->rear->next = novo; // antigo último aponta para novo
f->rear = novo; // rear passa a ser novo nó
}

void removerInicio (Fila *f){
    if(f->front== NULL){
        printf("Fila Vazia!");
        return;
    }

    Node *temp = f->front;
    f->front = f->front->next;

    if(f->front == NULL){
        f->rear=NULL;
    }

    free(temp);
}

void mostrarFila(Fila *f){
    Node *atual = f->front;

    if(atual == NULL){
        printf("Fila Vazia!");
        return;
    }

    printf("Fila: ");

    while(atual!=NULL){
        printf(" %d", atual->valor);
        atual = atual->next;
    }
    printf("\n");
    free(atual);
}

void mostrarPrimeiro(Fila *f){
     if(f->front== NULL){
        printf("Fila Vazia!");
        return;
    }
    printf("Primeiro item da fila: %d\n", f->front->valor);
}

void mostrarUltimo(Fila *f){
     if(f->rear== NULL){
        printf("Fila Vazia!");
        return;
    }
    printf("Último item da fila: %d\n", f->rear->valor);
}

int buscar(Fila *f, int valor){
    Node *atual = f->front;

    while (atual != NULL)
    {
        if(atual->valor == valor){
            return 1;
        }
        atual = atual->next;
    }
    return 0;
}

void liberaFila(Fila *f){
    Node *atual = f->front;

    while(atual != NULL){
        Node *temp = atual;
        atual = atual->next;
        free(temp);
    }

    f->front = NULL;
    f->rear = NULL;
}

int main(){
    Fila f;
    inicializar(&f);

   int op, valor;

   do{
    printf("1)Inserir elemento \n");
    printf("2)Remover elemento \n");
    printf("3)Mostrar Fila \n");
    printf("4)Mostrar 1° elemento \n");
    printf("5)Mostrar último elemento \n");
    printf("6)Buscar elemento \n");
    printf("7)Liberar Fila \n");
    printf("0)Sair \n");
    printf("Opção: \n");
    
    scanf(" %d", &op);

    switch (op)
    {
    case 1:
        {
            printf("Informe o valor a ser inserido: ");
            scanf(" %d", &valor);
            inserirFim(&f, valor);
        }
    break;

    case 2: 
    {
        removerInicio(&f);
    }
    break;

    case 3:
    {
        mostrarFila(&f);    
    }
    break;

    case 4:
    {
        mostrarPrimeiro(&f);
    }
    break;

    case 5:
    {
        mostrarUltimo(&f);
    }
    break;

    case 6:
    {
        printf("Informe o valor a ser procurado: ");
        scanf(" %d", &valor);
        if(buscar(&f, valor)){
            printf("Encontrado!\n");
        }else{
            printf("Não encontrado!\n");
        }
    }
    break;
    
    case 7:
    {
        liberaFila(&f);
    }
    break;

    default:
        printf("Algo deu errado!");
        break;
    }
    
   }while (op!=0);
    

}
