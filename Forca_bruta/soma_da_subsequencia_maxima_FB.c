#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sum_sub_max_fb(int *vet, int n)
{
  int sum = 0, biggest_suum = vet[0];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      for (int k = j; k <= i; k++)
      {
        sum += vet[k];
      }
      if (sum > biggest_suum)
        biggest_suum = sum;
      sum = 0;
    }
  }
  return biggest_suum;
}

int main()
{
  int n, *vet;
  scanf("%d", &n);
  vet = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &vet[i]);
  }
  printf("%d", sum_sub_max_fb(vet, n));
  free(vet);

  return 0;
}
