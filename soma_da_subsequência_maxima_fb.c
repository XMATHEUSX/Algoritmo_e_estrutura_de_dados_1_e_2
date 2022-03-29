#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char const *argv[])
{
  int row, *b,maior_global,soma,maior_local;
  scanf ("%d", &row);
  b = (int *) calloc (row+1, sizeof (int *));
  for (int i = 0; i < row; i++)
    scanf ("%d", &b[i]);
  for (int i = 0; i < row; i++)
  maior_global = b[0] ;
  for (int i = 0; i < row; i++){
    maior_local = b[i];
    soma = b[i];
    for (int j = i+1; j < row; j++)
      {
      soma += b[j];
        if (soma > maior_local)
          maior_local = soma;        }
      if (maior_local > maior_global){
        maior_global = maior_local;
      }
  }
  free (b);
  printf("%d",maior_global);
  return 0;
}
