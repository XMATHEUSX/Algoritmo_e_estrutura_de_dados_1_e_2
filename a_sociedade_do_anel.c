#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

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

int up(int **path, int i, int j, int row)
{
    i -= 1;
    if (i >= row || i < 0)
        return -1;
    else
        return path[i][j];
}

int down(int **path, int i, int j, int row)
{
    i += 1;
    if (i >= row)
        return -1;
    else
        return path[i][j];
}

int right(int **path, int i, int j, int col)
{
    j += 1;
    if (j >= col)
        return -1;
    else
        return path[i][j];
}

int left(int **path, int i, int j, int col)
{
    j -= 1;
    if (j >= col || j < 0)
        return -1;
    else
        return path[i][j];
}

int walk(int **path, int col, int row)
{
    int i = 0, j = 0, steps = 0, smallest_elemt = 0;
    int d, u, l, r;
    while (i != row - 1 || j != col - 1)
    {

        u = up(path, i, j, row);

        r = right(path, i, j, col);

        d = down(path, i, j, row);

        l = left(path, i, j, col);

        path[i][j] = INT_MAX;
        smallest_elemt = INT_MAX;
        if (smallest_elemt > u && u >= 0)
        {
            smallest_elemt = u;
        }
        if (smallest_elemt > r && r >= 0)
        {
            smallest_elemt = r;
        }
        if (smallest_elemt > d && d >= 0)
        {
            smallest_elemt = d;
        }
        if (smallest_elemt > l && l >= 0)
        {
            smallest_elemt = l;
        }
        if (smallest_elemt == u && u != INT_MAX)
        {
            i -= 1;
            steps += u;
        }
        else if (smallest_elemt == d && d != INT_MAX)
        {
            i += 1;
            steps += d;
        }
        else if (smallest_elemt == l && l != INT_MAX)
        {
            j -= 1;
            steps += l;
        }
        else if (smallest_elemt == r && r != INT_MAX)
        {
            j += 1;
            steps += r;
        }
        else if (smallest_elemt == INT_MAX)
        {
            break;
        }
    }
    if (smallest_elemt == INT_MAX)
    {
        return -1;
    }
    return steps;
}

int main(int argc, char const *argv[])
{
    int row, col, **field, steps;
    scanf("%d %d", &row, &col);
    field = allocate_matrix(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &field[i][j]);
        }
    }
    steps = walk(field, row, col);
    if (steps == -1)
    {
        printf("sem solucao");
    }
    else
    {
        printf("%d", steps);
    }
    free_matrix(field, row, col);
    return 0;
}