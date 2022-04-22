#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int rodCutting(int more[], int prices[], int rod_size)
{
    int cuts[rod_size];

    int i = 0;

    while (more[i] != NULL)
    {
        cuts[i] = more[i];
        i++;
    }
    cuts[i] = NULL;
    int aux = 0;
    int soma = 0;
    int total = 0;
    int maior_preco = 0;
    int *num;
    int n = 0;
    int r = 0;
    int j = 0, p = 0;
    while (cuts[n] != NULL)
    {
        n++;
    }
    r = n;
    num = (int *)calloc(r + 1, sizeof(int));
    while (num[r] == 0)
    {
        i++;
        aux = 0;
        soma = 0;
        for (j = 0; j < r; j++)
        {
            aux = (num[j]);

            aux = (cuts[aux] - 1);
            total += prices[aux];

            soma += aux;
        }
        if (soma == rod_size && total > maior_preco)
        {
            maior_preco = total;
        }
        aux = 0;
        soma = 0;
        total = 0;

        num[0]++;

        // distribui os vai-uns.
        for (int i = 0; i < r; i++)
        {
            if (num[i] == n)
            {
                num[i] = 0;
                num[i + 1]++;
            }
        }
    }
    free(num);
    return maior_preco;
}
int main()
{
    int rod_size, price_size;
    scanf("%d", &rod_size);
    scanf("%d", &price_size);
    price_size = price_size + 1;
    int teste[price_size];
    int more[rod_size];
    teste[0] = 0;
    for (int i = 1; i < price_size; i++)
    {
        scanf("%d", &teste[i]);
    }
    for (int i = 0; i <= rod_size; i++)
    {
        more[i] = i + 1;
        // printf("%d ",more[i]);
    }
    more[rod_size] = NULL;

    printf("%d", rodCutting(more, teste, rod_size));
    return 0;
}