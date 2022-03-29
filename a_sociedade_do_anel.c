#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int **cria_matriz(int n, int m)
{
    int i;
    int **mat;
    mat = (int **)calloc(n, sizeof(int *));
    for (i = 0; i < n; i++)
        mat[i] = (int *)calloc(m, sizeof(int));
    return mat;
}

int up(int **caminho,int i,int j, int row)
{
    i -= 1;
    if (i >= row || i < 0)
        return -1;
    else       
        return caminho[i][j];
}

int down(int **caminho,int i,int j, int row)
{
    i += 1;
    if (i >= row)
        return -1;
    else       
        return caminho[i][j];
}

int right(int **caminho,int i,int j, int col)
{
    j += 1;
    if (j >= col)
        return -1;
    else       
        return caminho[i][j];
}

int left(int **caminho,int i,int j, int col)
{
    j -= 1;
    if (j >= col || j < 0)
        return -1;
    else       
        return caminho[i][j];
}

int andar(int **caminho,int col, int row)
{
    int i=0,j=0,soma=0,menor;
    int d,u,l,r;
    //printf("%d ", caminho[i][j]);
    while (i != row-1 || j != col-1)
    {

        u = up(caminho,i,j,row);
        r = right(caminho,i,j,col);
        d = down(caminho,i,j,row);
        l = left(caminho,i,j,col);
        //printf("Caminho para cima:%d \n Caminho para  direita:%d \nCaminho para baixo:%d \n Caminho para  Esquerda:%d \n",u,r,d,l);
        
        //Tentar pensar uma nova forma de fazer isso 
        caminho[i][j] = INT_MAX;
        menor = INT_MAX;
        if(menor > u && u >= 0)
            menor = u; 
        if(menor > r && r >= 0)
            menor = r; 
        if(menor > d && d >= 0)
            menor = d;
        if(menor > l && l >= 0)
            menor = l;  
        if(menor == u&& u != INT_MAX)
        {
            i-=1;
            soma +=u; 
        }
        else if(menor == d && d != INT_MAX)
        {
            i+=1;
            soma +=d; 
        }
        else if(menor == l && l != INT_MAX)
        {
            j-=1;
            soma +=l; 
        }
        else if(menor == r && r != INT_MAX)
        {
            j+=1;
            soma +=r; 
        }
        else if(menor == INT_MAX)
            break;
        
    } 
    if(menor == INT_MAX)
        return -1;
    return soma;

}

int main(int argc, char const *argv[])
{
    int row,col, **b,passos;
    scanf("%d %d", &row , &col);
    b = cria_matriz(row,col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &b[i][j]);
    passos = andar(b,row,col);
    if (passos == -1)
        printf("sem solucao");
    else
        printf("%d",passos);
    for (int i = 0; i < row; i++)
        free(b[i]);
    free(b);
    return 0;
}