#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int **allocate_matrix(int rows, int columns)
{
    int **matrix;
    if (rows < 1 || columns < 1)
    {
        printf("invalid parameters");
        return NULL;
    }
    matrix = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)calloc(columns, sizeof(int));
    }
    return matrix;
}

int **free_matrix(int **matrix, int rows, int columns)
{
    if (matrix == NULL)
    {
        return NULL;
    }
    else if (rows < 1 || columns < 1)
    {
        printf("invalid parameters");
        return matrix;
    }
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return NULL;
}

void allocate_class(int **classes, int rows)
{
    int allocated_classes = 0;
    printf("Aulas alocadas: %d", allocated_classes);
    for (int i = 1; i < rows; i++)
    {
        if (classes[allocated_classes][1] < classes[i][0])
        {
            allocated_classes = i;
            printf(" %d", allocated_classes);
        }
    }
}
int *allocate_class_retur(int **classes, int rows)
{
    int allocated_classes = 0;
    int amount_allocated_classes = 1;
    int *vetor_allocated_class = (int *)calloc(amount_allocated_classes, sizeof(int));
    vetor_allocated_class[amount_allocated_classes - 1] = allocated_classes;
    for (int i = 1; i < rows; i++)
    {
        if (classes[allocated_classes][1] < classes[i][0])
        {
            allocated_classes = i;
            printf(" %d\n", vetor_allocated_class[amount_allocated_classes]);
            amount_allocated_classes++;
            vetor_allocated_class = realloc(vetor_allocated_class, amount_allocated_classes * sizeof(int));
            vetor_allocated_class[amount_allocated_classes - 1] = i;
        }
    }
    return vetor_allocated_class;
}

int main(int argc, char const *argv[])
{
    int rows, **classes, *teste;
    scanf("%d", &rows);
    classes = allocate_matrix(rows, 2);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &classes[i][j]);
        }
    }
    allocate_class(classes, rows);
    teste = allocate_class_retur(classes, rows);
    printf("Aulas alocadas:");
    for (int i = 0; i <= sizeof(*teste) / sizeof(int); i++)
    {
        printf(" %d", teste[i]);
    }
    free_matrix(classes, rows, 2);
    return 0;
}
