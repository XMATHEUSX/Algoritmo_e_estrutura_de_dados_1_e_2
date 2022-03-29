#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max(a, b) a > b ? a : b



int sub_max(int *vetor,int ini,int fim)
{
    int soma,meio,a,b;
    if (fim == ini)
    {
        return (vetor[ini]);
    }     
    else
    {
        meio = (ini+fim)/2;
        a = sub_max(vetor,ini,meio);
        b = sub_max(vetor,meio,fim);
        return a+b;
    }
        

} 



int main (int argc, char const *argv[])
{
    int row, *b;
    scanf ("%d", &row);
    b = (int *) calloc (row, sizeof (int *));
    for (int i = 0; i < row; i++)
        scanf ("%d", &b[i]);
    printf("%d",sub_max(b,0,row));
    free (b);
    return 0;
}
