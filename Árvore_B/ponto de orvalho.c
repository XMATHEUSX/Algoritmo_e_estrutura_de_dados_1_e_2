#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define A 17.625;
#define B 243.04;
float dew_point(float temp, float ur)
{
    return (B*formula_de_magnus(temp,ur))/(A-formula_de_magnus(temp,ur));
}

float formula_de_magnus(float temp, float ur)
{
    return(log(ur/100)+((A*temp)(/B+T)))
}

int main()
{
    NodeB *tree = criar();

    int items_tree, aux = 0, pont = 0, *cont;
    cont = &pont;
    scanf("%d", &items_tree);
    for (int i = 0; i < items_tree; i++)
    {
        scanf("%d", &aux);
        tree = inserir(tree, aux);
    }
    qtd_pag(tree, cont);
    if (pont != 0)
    {
        pont++;
    }
    printf("%d", pont);
    NodeB *auxb = tree->filhos[0];
    // printf("%d",auxb->filhos[3]->chaves[0]);
    // liberar(tree);
    return 0;
}