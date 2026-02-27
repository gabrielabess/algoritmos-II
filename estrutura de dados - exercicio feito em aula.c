#include<stdio.h>
#include<stdlib.h>


//Definição da estrutura do nó
typedef struct Node{
    int data;              //Valor armazenado
    struct Node *next;     //Ponteiro para o próximo
} Node;

//Função para inserção no início da lista
//Recebe o head para alterar ele
void inserirInicio(struct Node **head, int valor){
    struct Node *novo = (struct Node*) malloc(sizeof(struct Node)); //Alocar memoria para o novo nó
    if(novo == NULL){                                               //Verifica se a alocação deu certo
        printf("Erro de alocação!\n");
        exit (1);
    }
    novo->data = valor; //insere o valor no dado do novo nó                         
    novo->next = *head; //novo nó aponta para o head anterior
    *head = novo;       //head atualiza apontando para o novo nó
}


void inserirFinal(struct Node **head, int valor){
    struct Node *novo = (struct Node*) malloc(sizeof(struct Node)); //Alocar memoria para o novo nó
    if(novo == NULL){                                               //Verifica se a alocação deu certo
        printf("Erro de alocação!\n");
        exit (1);
    }
    novo->data = valor; //insere o valor no dado do novo nó                         
    novo->next =NULL; //novo nó aponta para o null (sendo o último)
    
	if(head==NULL){
	*head = novo;  //se o head for null ele é o primeiro elemento
	} 
	
	struct Node *temp = *head; //percorrer a lista até o último nó
	while (temp-> next != NULL){
	temp = temp -> next; 
	}
	temp->next = novo; //o ultimo vai apontar para o novo (que agora será último)
	
	while(head!=NULL){ //liberação de todos os nós
    temp = head;        //temp fica com o valor de head
    head = head->next;  //o head se torna o próximo
    free(temp);         //o temp é liberado (que é o head "anterior")
}                       //o ciclo reinicia com o novo head definido na L51
	}

//Função para exibir lista
void exibirLista(struct Node *head){
    struct Node *temp = head; // temp inicia no primeiro nó
    while (temp!=NULL){ //enquanto o temp for diferente de null (oq só acontece no tail) a impressão continua
        printf("%d -> ", temp->data);
        temp = temp->next; //temp atualiza para o ponteiro do próximo
    }
    printf("NULL\n");
}


int main (){
struct Node *head=NULL;
int valor;

for(int i=0; i<5; i++){  //inserção dos valores
    printf("Digite um valor: ");
    scanf("%d", &valor);
    inserirInicio(&head, valor);
}

printf("\nLista Final\n");
exibirLista(head);

struct Node *temp;
while(head!=NULL){ //liberação de todos os nós
    temp = head;        //temp fica com o valor de head
    head = head->next;  //o head se torna o próximo
    free(temp);         //o temp é liberado (que é o head "anterior")
}                       //o ciclo reinicia com o novo head definido na L51

return 0;
}
