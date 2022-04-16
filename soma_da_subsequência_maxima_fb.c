#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sub_max_fb( int *b,int row)
{ int maior_global,soma, maior_local;
 
 //sentando como o maior subsequencia o primeiro elemento
 maior_global = b[0];

  for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < row-i; j++)
    {
          for(int k = j; k < j+1; k++)
          {
      //soma das subsequC*ncias
      printf("%d-",b[k]);
      soma += b[k];
    
      if (soma > maior_local)
        maior_local = soma;
              }
    }
      printf("\n");
      if (maior_local > maior_global)
        maior_global = maior_local;
    }
 return maior_global;
    
}



int main (int argc, char const *argv[])
{
  int row, *b;
  scanf ("%d", &row);
  //alocando vetor b
  b = (int *) calloc (row, sizeof (int *));
  //atribuindo valores
  for (int i = 0; i < row; i++)
    scanf ("%d", &b[i]);
  printf("%d",sub_max_fb(b,row));
  //liberando o vetor alocado
  free (b);
  return 0;
}
