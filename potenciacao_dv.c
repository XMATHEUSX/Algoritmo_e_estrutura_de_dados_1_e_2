#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int potencia(a,n)
{
    int x;
    if (n == 0)
    {
        return 1;
    }
    else if (n==1)
    {
        return a;
    }
    else
    {
        if (n%2 == 0)
        { 
            x = potencia(a,n/2);
            return x*x;
        }
        else
        {
            x = potencia(a,(n-1)/2);
            return x*x*a;
        }
    }
}

int main(int argc, char const *argv[])
{
    int a,b,c;
    scanf("%d %d",&a, &b);
    c = potencia(a,b);
    printf("%d",c);
}