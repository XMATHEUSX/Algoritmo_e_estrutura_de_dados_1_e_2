#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max2(a, b) a > b ? a : b

int **cria_matriz(int n, int m)
{
    int i;
    int **mat;
    mat = (int **)calloc(n, sizeof(int *));
    for (i = 0; i < n; i++)
        mat[i] = (int *)calloc(m, sizeof(int));
    return mat;
}
void mochila(int c[], int p[], int n, int b)
{
    int **matriz_aux;
    matriz_aux = cria_matriz(b + 1, n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (j - p[i - 1] < 0)
            {

                matriz_aux[j][i] = max2(matriz_aux[j][i - 1], 0);
            }
            else
            {
                matriz_aux[j][i] = max2(matriz_aux[j][i - 1], c[i - 1] + matriz_aux[(j - p[i - 1])][i - 1]);
            }
        }
    }
    /*printf("\n");
    for (int i = 0; i <= b; i++)
    {
        printf("%d ", i);
        for (int j = 0; j <= n; j++)
        {

        }
        printf("\n");
    }*/
    return matriz_aux[b][n];
}
int main(int argc, char const *argv[])
{
    int ta_moc, qtd, *preco, *pesos;
    scanf("%d", &ta_moc);
    scanf("%d", &qtd);
    preco = (int *)calloc(qtd, sizeof(int));
    pesos = (int *)calloc(qtd, sizeof(int));
    for (int i = 0; i < qtd; i++)
    {
        scanf("%d  %d ", &pesos[i], &preco[i]);
    }
    mochila(preco, pesos, qtd, ta_moc);
    free(preco);
    free(pesos);
    return 0;
}