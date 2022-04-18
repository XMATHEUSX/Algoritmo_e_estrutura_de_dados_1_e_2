#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int cut_rod(int rod_size, int *price, int list_price)
{

    int divisions = 0, sale_price = 0, biggest_price = INT_MIN, rest = 0;

    if (rod_size == 0)
    {
        return 0;
    }
    for (int i = 1; i <= list_price; i++)
    {
        if ((rod_size % i) == 0)
        {
            divisions = rod_size / i;
            sale_price = divisions * price[i - 1];
            if (sale_price > biggest_price)
            {
                biggest_price = sale_price;
            }
            // printf("%d divisoes de %d polegadas e seu preco de venda e %d\n",divisoes,i,venda);
        }
        else if ((rod_size % i) != rod_size)
        {
            divisions = rod_size / i;
            rest = rod_size % i;
            sale_price = divisions * price[i - 1];
            // printf(" %d divisoes de %d polegadas e seu preco de venda e %d\n",divisoes,i,venda);
            divisions = cut_rod(rest, price, list_price);
            sale_price += divisions;
            // printf(" novo %d divisoes de %d polegadas e seu preco de venda e %d\n",divisoes,i,venda);
        }
    }
    return biggest_price;
}

int main(int argc, char const *argv[])
{
    int rod_size, *prices, list_price;
    scanf("%d", &rod_size);
    scanf("%d", &list_price);
    prices = (int *)calloc(list_price, sizeof(int));
    for (int i = 0; i < list_price; i++)
    {
        scanf("%d", &prices[i]);
    }
    printf("%d", cut_rod(rod_size, prices, list_price));
    free(prices);
    return 0;
}