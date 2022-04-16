#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

void cortes(int haste)
{
    int divisoes;
    for (int i = 1; i <= 10; i++)
    {
        if ((haste % i) == 0)
        {
            divisoes = haste / i;
            printf("%d divisoes de %d polegadas", divisoes, i);
        }
    }
}

int main(int argc, char const *argv[])
{
    int tam_haste, *precos, lista_preco;
    scanf("%d", &tam_haste);
    scanf("%d", &lista_preco);
    precos = (int *)calloc(lista_preco, sizeof(int));
    for (int i = 0; i < lista_preco; i++)
    {
        scanf("%d", &precos[i]);
    }
    cortes(tam_haste);
    free(precos);
    return 0;
}