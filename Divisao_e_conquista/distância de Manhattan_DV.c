#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int dist_ma(int *v1, int *v2, int begin, int end)
{
    int sum = 0, middle;

    if (end == begin)
    {
        sum = abs((v1[begin] - v2[end]));
        return sum;
    }
    else
    {
        middle = (begin + end) / 2;
        sum += dist_ma(v1, v2, begin, middle);
        sum += dist_ma(v1, v2, middle + 1, end);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n, *v1, *v2;
    scanf("%d", &n);
    v1 = (int *)calloc(n, sizeof(int));
    v2 = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v2[i]);
    }
    printf("%d", dist_ma(v1, v2, 0, n));
    free(v1);
    free(v2);
    return 0;
}