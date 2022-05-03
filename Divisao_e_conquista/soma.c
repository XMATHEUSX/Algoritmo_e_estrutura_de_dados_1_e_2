#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void soma_dv(int *a, int b)
{
    if (b == 1)
    {
        (*a)++;
    }
    else if (b > 1)
    {
        if (b % 2 == 1)
        {
            (*a)++;
        }
        soma_dv(a, b / 2);
        soma_dv(a, b / 2);
    }
}

int main(int argc, char const *argv[])
{
    int a, b, *c;
    scanf("%d %d", &a, &b);
    c = &a;
    soma_dv(c, b);
    printf("%d", a);
    return 0;
}
