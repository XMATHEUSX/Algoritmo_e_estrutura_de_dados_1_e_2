#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

struct GrafoMA
{
    int V;
    int A;
    int **mat;
} typedef GrafoMA;

struct busca_pro
{
    int cor;
    int d;
    int f;
    int pai;
} typedef BPS; // Busca em produndidade Struct

// Matriz

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

void inserir_aresta(GrafoMA *G, int v1, int v2)
{
    if (!aresta_existe(G, v1, v2))
    {
        G->mat[v1][v2] = 1;
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
            if (G->mat[i][j] == 1)
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

void busca_em_profundidade_visita(GrafoMA *G, BPS *aux, int i, int *tempo)
{
    aux[i].cor = 0;
    (*tempo)++;
    aux[i].d = *tempo;
    for (int j = 0; j < G->V; j++)
    {
        if (G->mat[i][j] == 1)
        {
            printf("%d - %d\n", i, j);
            if (aux[j].cor == -1)
            {
                aux[j].pai = i;

                busca_em_profundidade_visita(G, aux, j, tempo);
            }
        }
    }
    aux[i].cor = 1;
    (*tempo)++;
    aux[i].f = *tempo;
}

void busca_em_profundidade(GrafoMA *G)
{
    // branco = -1
    // cinza = 0
    // preto = 1
    BPS aux[G->V];
    int *pont_tempo, tempo = 0;
    pont_tempo = &tempo;

    for (int i = 0; i < G->V; i++)
    {
        aux[i].cor = aux[i].pai = -1;
    }
    for (int i = 0; i < G->V; i++)
    {
        if (aux[i].cor == -1)
        {
            busca_em_profundidade_visita(G, aux, i, pont_tempo);
        }
    }

    printf("v d f p\n");
    for (int i = 0; i < G->V; i++)
    {
        if (aux[i].pai == -1)
        {
            printf("%d %d %d -\n", i, aux[i].d, aux[i].f);
        }
        else
        {
            printf("%d %d %d %d\n", i, aux[i].d, aux[i].f, aux[i].pai);
        }
    }
}

int main()
{
    int vertices = 0, aresta = 0, j = 0, k = 0;
    GrafoMA *matriz;
    scanf("%d", &vertices);
    scanf("%d", &aresta);
    matriz = iniciar_grafoMA(vertices);
    for (int i = 0; i < aresta; i++)
    {
        scanf("%d", &j);
        scanf("%d", &k);
        inserir_aresta(matriz, j, k);
    }
    busca_em_profundidade(matriz);
}
