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

typedef struct ItemF
{
    int chave;
} ItemF;

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

    for (i = 0; i < G->V; i++)
        for (j = 0; j < G->V; j++)
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

void busca_em_profundidade(GrafoMA *G)
{
    // branco = -1
    // cinza = 0
    // preto = 1
    BPS aux[G->V];
    int *pont_tempo, tempo = 0;
    int *pont_aresta_ret, aresta_ret = 0;
    pont_tempo = &tempo;
    pont_aresta_ret = &aresta_ret;

    for (int i = 0; i < G->V; i++)
    {
        aux[i].cor = aux[i].pai = -1;
    }
    for (int i = 0; i < G->V; i++)
    {
        if (aux[i].cor == -1)
        {
            busca_em_profundidade_visita(G, aux, i, pont_tempo, pont_aresta_ret);
        }
    }
    if (aresta_ret >= 1)
    {
        printf("ciclico");
    }
    else
    {
        printf("aciclico");
    }
}

void busca_em_profundidade_visita(GrafoMA *G, BPS *aux, int i, int *tempo, int *aresta_ret)
{
    aux[i].cor = 0;
    (*tempo)++;
    aux[i].d = *tempo;
    for (int j = 0; j < G->V; j++)
    {
        if (G->mat[i][j] == 1)
        {
            // printf("%d - %d\n", i, j);

            if (aux[j].cor == -1)
            {
                aux[j].pai = i;

                busca_em_profundidade_visita(G, aux, j, tempo, aresta_ret);
                // printf("(%d cor: %d\n",j,aux[j].cor);
            }
            else if (aux[j].cor == 1 && G->mat[j][i] == 1)
            {
                (*aresta_ret)++;
                // printf("++(%d, %d),cor: %d\n", i, j,aux[j].cor);
            }
        }
    }
    aux[i].cor = 1;
    (*tempo)++;
    aux[i].f = *tempo;
}

int main()
{
    int tam_ma = 0, aux = 0;
    GrafoMA *matriz;
    scanf("%d", &tam_ma);
    matriz = iniciar_grafoMA(tam_ma);
    for (int i = 0; i < tam_ma; i++)
    {
        for (int j = 0; j < tam_ma; j++)
        {
            scanf("%d", &aux);
            if (aux == 1)
            {
                inserir_aresta(matriz, i, j);
            }
        }
    }
    busca_em_profundidade(matriz);
}
