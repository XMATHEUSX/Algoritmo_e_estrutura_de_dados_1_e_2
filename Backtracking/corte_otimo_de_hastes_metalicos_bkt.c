#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int rodCutting(int cuts[], int prices[], int rod_size)
{

    int i = 0, aux = 0, sum = 0, total = 0, biggest_price = 0;
    int r = 0, j = 0;
    int *num;
    while (cuts[i] != NULL)
    {
        i++;
    }
    r = i;
    num = (int *)calloc(r + 1, sizeof(int));
    biggest_price = prices[r];
    while (num[r] == 0)
    {
        aux = 0;
        sum = 0;
        total = 0;

        for (j = 0; j < r; j++)
        {
            aux = (num[j]);
            aux = (cuts[aux] - 1);
            total += prices[aux];
            sum += aux;
        }

        if (sum == rod_size && total > biggest_price)
        {
            biggest_price = total;
        }
        num[0]++;

        for (int i = 0; i < r; i++)
        {
            if (num[i] == r)
            {
                num[i] = 0;
                num[i + 1]++;
            }
        }
    }
    free(num);
    return biggest_price;
}
int main()
{
    int rod_size, price_size;
    scanf("%d", &rod_size);
    scanf("%d", &price_size);
    price_size++;
    int prices[price_size];
    int cuts[rod_size];
    prices[0] = 0;

    for (int i = 1; i < price_size; i++)
    {
        scanf("%d", &prices[i]);
    }

    for (int i = 0; i <= rod_size; i++)
    {
        cuts[i] = i + 1;
    }

    cuts[rod_size] = NULL;

    printf("%d", rodCutting(cuts, prices, rod_size));

    return 0;
}