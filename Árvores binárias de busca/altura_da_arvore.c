/*
Implemente uma função que receba uma árvore binária de busca. A função deverá retornar a altura da árvore.

Input Format

Na primeira linha deve ser lido o número inteiro N, que é referente à quantidade de nós da árvore binária de busca. Em seguida, em cada linha deve ser lido um número inteiro para ser inserido como nó na árvore (fazer isso até que N números sejam lidos).

Constraints

.

Output Format

O valor da altura da árvore.

Lembre-se: a altura do nó raiz é zero.

Sample Input 0

13
28
12
8
3
10
9
15
16
45
36
41
59
48

Sample Output 0

4



*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node
{

    int item;
    struct Node *left;
    struct Node *right;

} Node;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *criar(int item)
{
    Node *tree = (Node *)malloc(sizeof(Node));

    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

Node *inserir(int item, Node *tree)
{
    if (tree == NULL)
    {
        tree = criar(item);
    }
    else if (item < tree->item)
    {
        tree->left = inserir(item, tree->left);
    }
    else if (item > tree->item)
    {
        tree->right = inserir(item, tree->right);
    }

    return tree;
}

int altura(Node *tree)
{
    int altD, altE;
    Node *treeD, *treeE;

    altD = 0;
    altE = 0;
    treeE = tree;
    treeD = tree;

    if (tree == NULL)
    {
        return -1;
    }
    else
    {
        while (treeE->left != NULL)
        {
            treeE = treeE->left;

            if (treeE->left == NULL && treeE->right != NULL)
            {
                altE++;

                treeE = treeE->left->right;
            }

            altE++;
        }

        while (treeD->right != NULL)
        {
            treeD = treeD->right;

            if (treeD->right == NULL && treeD->left != NULL)
            {
                altD++;

                treeD = tree->right->left;
            }

            altD++;
        }
    }

    return max(altD, altE);
}

int main()
{

    int i, num, tam;
    Node *avr;

    scanf("%d", &tam);

    for (i = 0; i < tam; i++)
    {
        scanf("%d", &num);

        if (i == 0)
        {
            avr = criar(num);
        }
        else
        {
            inserir(num, avr);
        }
    }

    printf("%d", altura(avr));

    return 0;
}