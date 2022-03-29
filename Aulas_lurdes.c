#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int **cria_matriz(int n)
{
    int i;
    int **mat;
    mat = (int **)calloc(n, sizeof(int *));
    for (i = 0; i < n; i++)
        mat[i] = (int *)calloc(2, sizeof(int));
    return mat;
}

void aloca_aula(int **aulas,int row)
{
    int alocada = 0;
    printf("Aulas alocadas: %d",alocada);
    for (int i = 1; i < row; i++)
    {
        if (aulas[alocada][1] < aulas[i][0])
        {
            alocada = i;
            printf(" %d ",alocada);
        }
    }
}

int main(int argc, char const *argv[])
{
    int row, **b;
    scanf("%d", &row);
    b = cria_matriz(row);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &b[i][j]);
    aloca_aula(b,row);
    for (int i = 0; i < row; i++)
        free(b[i]);
    free(b);
    return 0;
}