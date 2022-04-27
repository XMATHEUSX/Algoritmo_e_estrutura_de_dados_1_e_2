#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int som_sub_max(int *b, int row)
{
    int maior_global, soma, maior_local;

    maior_global = b[0];

    for (int i = 0; i < row; i++)
    {

        maior_local = b[i];
        soma = b[i];

        for (int j = i + 1; j < row; j++)
        {
            soma += b[j];

            if (soma > maior_local)
                maior_local = soma;
        }
        if (maior_local > maior_global)
            maior_global = maior_local;
    }
    return maior_global;
}

int main(int argc, char const *argv[])
{
    int row, *b;
    scanf("%d", &row);
    b = (int *)calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++)
        scanf("%d", &b[i]);

    printf("%d", som_sub_max(b, row));
    free(b);

    return 0;
}
