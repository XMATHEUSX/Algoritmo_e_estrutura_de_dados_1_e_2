#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mult_dv(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    else if (b == 1)
    {
        return a;
    }
    else if (b % 2 == 1)
    {
        return a + mult_dv(a, b / 2) + mult_dv(a, b / 2);
    }
    else
    {
        return mult_dv(a, b / 2) + mult_dv(a, b / 2);
    }
}

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", mult_dv(a, b));
    return 0;
}
