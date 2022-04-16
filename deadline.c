#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mochila_dq(int c[], int p[], int *b, int ini, int fim)
{
    int meio;
    if (fim == ini)
    {
        if ((
                *b - p[ini] >= 0))
        {
            *b -= p[ini];
            return c[ini];
        }
        else
            return 0;
    }
    else
    {
        meio = (ini + fim) / 2;
        return mochila_dq(c, p, b, ini, meio) +
               mochila_dq(c, p, b, meio + 1, fim);
    }
}
int mochila(int c[], int p[], int n, int b)
{
    int aux = b;
    return mochila_dq(c, p, n, &aux, 0, n - 1);
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
    for (int i = 0; i < qtd; i++)
    {
        printf("\n%d  %d ", pesos[i], preco[i]);
    }
    free(preco);
    free(pesos);
    return 0;
}