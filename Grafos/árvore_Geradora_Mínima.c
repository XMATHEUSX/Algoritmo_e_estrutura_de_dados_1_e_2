#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define TAM_MAX 100

struct GrafoMA
{
    int V;
    int A;
    int **mat;
} typedef GrafoMA;

struct Prim
{
    int id;
    int key;
    int pai;
} typedef Prim; // Busca em largura Struct

typedef struct Fila
{
    Prim item[TAM_MAX];
    int ini;
    int fim;
    int tam;
} Fila;

Fila *criar_fila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}

int fila_cheia(Fila *f)
{

    if (f == NULL)
        return -1;
    else if (f->tam < TAM_MAX)
        return 0;
    else
        return 1;
}

int fila_vazia(Fila *f)
{
    if (f == NULL)
        return -1;
    else if (f->tam > 0)
        return 0;
    else
        return 1;
}

int enfileirar(Fila *f, int chave)
{
    Prim item;

    if (f == NULL)
        f = criar_fila();

    if (!fila_cheia(f))
    {
        item.id = chave;

        if (f->ini < 0)
            f->ini = 0;

        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;

        f->item[f->fim] = item;

        f->tam++;

        return 1;
    }

    return 0;
}

Prim *desenfileirar(Fila *f)
{
    Prim *item = NULL;

    if (!fila_vazia(f))
    {
        item = (Prim *)malloc(sizeof(Prim));

        *item = f->item[f->ini];

        if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;

        f->tam--;

        if (f->tam == 0)
        {
            f->ini = -1;
            f->fim = -1;
        }
    }

    return item;
}

void liberar_fila(Fila *f)
{
    if (f != NULL)
        free(f);
}

void liberar_itemF(Prim *item)
{
    if (item != NULL)
        free(item);
}

static int **iniciar_MA(int n)
{
    int i;
    int **mat = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
        mat[i] = (int *)calloc(n, sizeof(int));

    return mat;
}

static int valida_vertice(GrafoMA *G, int v)
{
    return (v >= 0) && (v < G->V);
}

GrafoMA *iniciar_grafoMA(int v)
{
    GrafoMA *G = (GrafoMA *)malloc(sizeof(GrafoMA));

    G->V = v;
    G->A = 0;
    G->mat = iniciar_MA(G->V);

    return G;
}

int aresta_existe(GrafoMA *G, int v1, int v2)
{
    return (G != NULL) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->mat[v1][v2] != 0);
}

void inserir_aresta(GrafoMA *G, int v1, int v2, int aux)
{
    if (!aresta_existe(G, v1, v2))
    {
        G->mat[v1][v2] = aux;
        G->A++;
    }
}

void remover_aresta(GrafoMA *G, int v1, int v2)
{
    if (aresta_existe(G, v1, v2))
    {
        G->mat[v2][v1] = G->mat[v1][v2] = 0;
        G->A--;
    }
}

void imprimir_arestas(GrafoMA *G)
{
    int i, j;

    for (i = 1; i < G->V; i++)
        for (j = 0; j < i; j++)
            if (G->mat[i][j] >= 1)
                printf("(%d, %d)\n", i, j);
    printf("(Aresta = %d, vertice = %d)\n", G->A, G->V);
}

void liberarGMA(GrafoMA *G)
{
    if (G != NULL)
    {
        free(G->mat);
        free(G);
    }
}

void alg_prim(GrafoMA *G, int r)
{
    ItemF *u;
    Fila *p = criar_fila();

    Prim aux[G->V];
    aux[r].pai = -1;
    aux[r].key = 0;
    for (int i = 0; i < G->V; i++)
    {
        if (i != r)
        {
            aux[i].pai = -1;
            aux[i].key = INT_MAX;
        }
        enfileirar(p, i);
    }
    while (p->tam != 0)
    {
        int menor = INT_MAX, u;
        for (int i = 0; i < p->tam; i++)
        {
            if (aux[i].key < menor)
            {
                menor = aux[i].key;
                p = i;
            }
        }
        u = desenfileirar(p);
    }
}

int main()
{
    int tam_ma = 0, aux = 0, s;
    GrafoMA *matriz;
    scanf("%d", &tam_ma);
    matriz = iniciar_grafoMA(tam_ma);
    for (int i = 0; i < tam_ma; i++)
    {
        for (int j = 0; j < tam_ma; j++)
        {
            scanf("%d", &aux);
            if (aux >= 1)
            {
                inserir_aresta(matriz, i, j, aux);
            }
        }
    }
    // scanf("%d", &s);
    // busca_em_largura(matriz, s);
    printf(matriz->mat[3][4]);
}