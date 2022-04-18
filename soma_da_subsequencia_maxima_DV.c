#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define max2(a, b) a > b ? a : b
#define max3(a, b, c) max2(max2(a, b), c)

int sum_sub_max_dv(int *v, int begin, int end)
{
  int sum = 0, middle, biggest_sum, i, aux = 0, s_left = INT_MIN, s_right = INT_MIN;
  biggest_sum = v[begin];
  middle = (begin + end) / 2;
  if (end == begin)
  {
    if (v[begin] > biggest_sum)
    {
      biggest_sum = v[begin];
    }
  }
  else
  {
    for (i = middle; i >= begin; i--)
    {
      aux += v[i];
      if (aux > s_left)
      {
        s_left = aux;
      }
    }
    aux = 0;

    for (i = middle + 1; i < end; i++)
    {
      aux += v[i];
      if (aux > s_right)
      {
        s_right = aux;
      }
    }
    sum = max3(s_left, s_right, s_left + s_right);

    if (sum > biggest_sum)
    {
      biggest_sum = sum;
    }
  }
  return biggest_sum;
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
  printf("%d", sum_sub_max_dv(vet, 0, n));
  free(vet);

  return 0;
}
