#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define max2(a, b) a > b ? a : b
#define max3(a, b, c) max2(max2(a, b), c)

int sub_max (int *vetor, int ini, int fim)
{
  int soma = 0, meio, a, b, maior_soma;
  int i, aux = 0, s_esq = INT_MIN, s_dir = INT_MIN;
  maior_soma = vetor[ini];
    meio = (ini+fim)/2;
  if (fim == ini)
    {
      if (vetor[ini] > maior_soma)
    {
      maior_soma = vetor[ini];
    }
    }
  else
    {
      for (i = meio; i >= ini; i--)
    {
      aux += vetor[i];
    printf ("%d ", vetor[i]);

      if (aux > s_esq)
        s_esq = aux;
    }
printf ("\n ");
      aux = 0;

      for (i = meio + 1; i < fim; i++)
    {
      aux += vetor[i];
printf ("%d ", vetor[i]);
      if (aux > s_dir)
        s_dir = aux;
    }
printf ("\n ");
  soma = max3(s_esq, s_dir, s_esq + s_dir);

      if (soma > maior_soma)
    {
      maior_soma = soma;
    }
  }
  return maior_soma;
}
int main (int argc, char const *argv[])
{
  int row, *b;
  scanf ("%d", &row);
  b = (int *) calloc (row, sizeof (int *));
  for (int i = 0; i < row; i++)
    scanf ("%d", &b[i]);
  printf ("%d", sub_max (b, 0, row));
  free (b);
  return 0;
}
