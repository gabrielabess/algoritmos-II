#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Musica {
    char title[100];
    char artist[100];
} Musica;

typedef struct No {
    Musica musica;
    struct No *prox;
    struct No *ant;
} No;

typedef struct Playlist {
    No *head;
    No *tail;
} Playlist;

void inicializar(Playlist *p) {
    p->head = NULL;
    p->tail = NULL;
}

void voltar_pular(Playlist *p, No *atual) {
    char op;
    do {
        printf("\n♫ ♬ ♪ Tocando agora: %s - %s\n", atual->musica.title, atual->musica.artist);
        printf("<< [V] Voltar  |  [A] Avançar  |  [S] Sair >>\n");
        printf("Opção desejada: ");
        scanf(" %c", &op);

        if (op == 'V' || op == 'v') {
            if (atual->ant != NULL) {
                atual = atual->ant;
            } else {
                printf("\n⚠️ Início da playlist! Não há anterior. Voltando ao menu...\n");
                op = 'S';
            }
        } 
        else if (op == 'A' || op == 'a') {
            if (atual->prox != NULL) {
                atual = atual->prox;
            } else {
                printf("\n⚠️ Fim da playlist! Não há próxima. Voltando ao menu...\n");
                op = 'S';
            }
        }
    } while (op != 'S' && op != 's');
}

void inserir_inicio(Playlist *p, Musica musica) {
    No *novo = (No *)malloc(sizeof(No));
    novo->musica = musica;
    novo->ant = NULL;
    novo->prox = p->head;
    if (p->head != NULL) p->head->ant = novo;
    else p->tail = novo;
    p->head = novo;
}

void inserir_fim(Playlist *p, Musica musica) {
    No *novo = (No *)malloc(sizeof(No));
    novo->musica = musica;
    novo->prox = NULL;
    novo->ant = p->tail;
    if (p->tail != NULL) p->tail->prox = novo;
    else p->head = novo;
    p->tail = novo;
}

void mostrar_Playlist(Playlist *p) {
    No *atual = p->head;
    printf("\n♫ ♬ ♪ ♫ ♬ ♪ ♫ PLAYLIST ♫ ♬ ♪ ♫ ♬ ♪ ♫ \n");
    if (atual == NULL) printf("\n ------------ PLAYLIST VAZIA! ------------\n");
    while (atual != NULL) {
        printf("♫ Titulo: %s - Artista: %s\n", atual->musica.title, atual->musica.artist);
        atual = atual->prox;
    }
}

No *buscar(Playlist *p, char titulo[]) {
    No *atual = p->head;
    while (atual != NULL) {
        if (strcmp(atual->musica.title, titulo) == 0) return atual;
        atual = atual->prox;
    }
    return NULL;
}

int tocar(Playlist *p, char titulo[]) {
    No *atual = p->head;

    while (atual != NULL) {
        if (strcmp(atual->musica.title, titulo) == 0) {
            voltar_pular(p, atual); 
            return 1;
        }
        atual = atual->prox;
    }

    printf("⚠️ Música não encontrada! ⚠️\n");
    return 0;
}

int inserir_apos(Playlist *p, char titulo[], Musica nova)
{
    No *atual = buscar(p, titulo);

    if (atual == NULL)
    {
        printf("⚠️ Música não encontrada! ⚠️\n");
        printf("\n♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬\n");
        return 0;
    }

    No *novo = (No *)malloc(sizeof(No));
    novo->musica = nova;

    novo->prox = atual->prox;
    novo->ant = atual;

    if (atual->prox != NULL)
        atual->prox->ant = novo;
    else
        p->tail = novo;

    atual->prox = novo;

    printf("♪ ♫ ♬ Música inserida com sucesso! ♪ ♫ ♬\n");
    printf("\n♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬\n");
    return 1;
}

int remover_musica(Playlist *p, char titulo[])
{
    No *atual = p->head;

    while (atual != NULL && strcmp(atual->musica.title, titulo) != 0)
    {
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("⚠️ Música não encontrada! ⚠️\n");
        printf("\n♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬\n");
        return 0;
    }

    if (atual == p->head && atual == p->tail)
    {
        p->head = NULL;
        p->tail = NULL;
    }
    else if (atual == p->head)
    {
        p->head = atual->prox;
        p->head->ant = NULL;
    }
    else if (atual == p->tail)
    {
        p->tail = atual->ant;
        p->tail->prox = NULL;
    }
    else
    {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
    }

    free(atual);

    printf("------ Música removida com sucesso! ------ \n");
    return 1;
}

void excluir(Playlist *p)
{
    No *atual = p->head;
    No *temp;

    while (atual != NULL)
    {
        temp = atual;
        atual = atual->prox;
        free(temp);
    }

    printf("------ PLAYLIST EXCLUÍDA ------\n");

    p->head = NULL;
    p->tail = NULL;
}

int main()
{
    Playlist p;
    Musica m;
    char busca[100];
    int menu;

    inicializar(&p);

    printf("\n===================================================");
    printf("\n   ♪ ♫ ♬ ♪ ♫ ♬ REPRODUTOR DE MÚSICA ♪ ♫ ♬ ♪ ♫ ♬\n"); //nao apagar os espacos extras, pois eles centralizam o título!
    printf("===================================================\n");

    do
    {
        printf("\n♪ ♪ ♪ MENU PRINCIPAL ♪ ♪ ♪\n");
        printf("\n1 - INSERIR MÚSICA NO INÍCIO\n");
        printf("2 - INSERIR MÚSICA NO FINAL\n");
        printf("3 - MOSTRAR PLAYLIST\n");
        printf("4 - TOCAR MÚSICA\n");
        printf("5 - BUSCAR MÚSICA\n");
        printf("6 - REMOVER MÚSICA\n");
        printf("7 - EXCLUIR PLAYLIST\n");
        printf("8 - INSERIR APÓS MÚSICA ESPECÍFICA\n");
        printf("0 - SAIR\n");
        printf("\n♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬ ♪ ♫ ♬\n");
        printf("---------------- SELECIONE A OPÇÃO DESEJADA ----------------\n");
        scanf("%d", &menu);
        getchar();

        switch (menu)
        {
        case 1:
            printf("♫ Digite o título da música: ");
            fgets(m.title, 100, stdin);
            m.title[strcspn(m.title, "\n")] = '\0';

            printf("Digite o artista: ");
            fgets(m.artist, 100, stdin);
            m.artist[strcspn(m.artist, "\n")] = '\0';

            inserir_inicio(&p, m);
            break;
        case 2:
            printf("♫ Digite o título da música: ");
            fgets(m.title, 100, stdin);
            m.title[strcspn(m.title, "\n")] = '\0';
            printf("Digite o artista: ");
            fgets(m.artist, 100, stdin);
            m.artist[strcspn(m.artist, "\n")] = '\0';
            inserir_fim(&p, m);
            break;
        case 3:
            mostrar_Playlist(&p);
            break;
        case 4:
            printf("♫ Digite uma música para tocar: ");
            fgets(busca, 100, stdin);
            busca[strcspn(busca, "\n")] = '\0';

            tocar(&p, busca);
            break;
        case 5:
            printf("♫ Digite o título da música que você deseja procurar: ");
            fgets(busca, 100, stdin);
            busca[strcspn(busca, "\n")] = '\0';
            No *resultado = buscar(&p, busca);
            break;
        case 6:
            printf("♫ Digite um titulo para remover: ");
            fgets(busca, 100, stdin);
            busca[strcspn(busca, "\n")] = '\0';
            remover_musica(&p, busca);
            break;
        case 7:
            excluir(&p);
            break;
        case 8:
            printf("♫ Digite o título da música que deseja inserir após: ");
            fgets(busca, 100, stdin);
            busca[strcspn(busca, "\n")] = '\0';

            printf("♫ Digite o título da música: ");
            fgets(m.title, 100, stdin);
            m.title[strcspn(m.title, "\n")] = '\0';

            printf("Digite o artista: ");
            fgets(m.artist, 100, stdin);
            m.artist[strcspn(m.artist, "\n")] = '\0';

            inserir_apos(&p, busca, m);
            break;
        case 0:
            printf("♪ ♫ ♬ SAINDO ♪ ♫ ♬\n");
            break;
        default:
            printf("Digite uma opção válida! ");
        }

    } while (menu != 0);

    return 0;
}
