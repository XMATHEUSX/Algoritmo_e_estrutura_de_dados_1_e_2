#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    //int id; // identificador da tarefa, que será a i-ésima tarefa lida
    int e; // tempo de execução
    int d; // deadline
}tarefa;

tarefa *cria_matriz(int n)
{
    int i;
    int *mat;
    mat = (tarefa *)calloc(n, sizeof(tarefa *));
    return mat;
}

tarefa adiciona_tarefa()
{
    tarefa processo;

    scanf("%d",&processo.e);

    scanf("%d",&processo.d);

    return processo;

}

int main(int argc, char const *argv[])
{
    int row, *b;
    tarefa *a1;
    scanf("%d", &row);
    a1 = cria_matriz(row);
    for (int i = 0; i < row; i++)
            a1[i] = adiciona_tarefa();
    for (int i = 0; i < row; i++)
            printf("\n\n%d %d\n",a1[i].e , a1[i].d);
    free(a1);
    return 0;
}