#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int item;
    struct Node *left;
    struct Node *right;
} typedef Node;

struct Pointer
{
    int item;
    int fb;
    struct Pointer *left;
    struct Pointer *right;
} typedef Node_avl;

Node *create_node(int item)
{
    Node *tree = (Node *)malloc(sizeof(Node));

    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

Node *insert(int item, Node *tree)
{

    if (tree == NULL)
        tree = create_node(item);

    else if (item < tree->item)
        tree->left = insert(item, tree->left);

    else if (item > tree->item)
        tree->right = insert(item, tree->right);

    return tree;
}

void imprimirPrefix(Node *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->item);
        imprimirPrefix(tree->left);
        imprimirPrefix(tree->right);
    }
}

Node_avl *criar(int item)
{
    Node_avl *tree = (Node_avl *)malloc(sizeof(Node_avl));

    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;
    tree->fb = 0;

    return tree;
}

static Node_avl *rotateL(Node_avl *tree)
{
    Node_avl *auxA = tree->left, *auxB;

    if (auxA->fb == +1)
    {
        tree->left = auxA->right;
        auxA->right = tree;
        tree->fb = 0;
        tree = auxA;
    }
    else
    {
        auxB = auxA->right;
        auxA->right = auxB->left;
        auxB->left = auxA;
        tree->left = auxB->right;
        auxB->right = tree;

        if (auxB->fb == +1)
            tree->fb = -1;
        else
            tree->fb = 0;

        if (auxB->fb == -1)
            auxA->fb = +1;
        else
            auxA->fb = 0;

        tree = auxB;
    }

    return tree;
}

static Node_avl *rotateR(Node_avl *tree)
{

    Node_avl *auxA = tree->right, *auxB;
    if (auxA->fb == -1)
    {
        tree->right = auxA->left;
        auxA->left = tree;
        tree->fb = 0;
        tree = auxA;
    }
    else
    {
        auxB = auxA->left;
        auxA->left = auxB->left;
        auxB->right = auxA;
        tree->right = auxB->left;
        auxB->left = tree;

        if (auxB->fb == -1)
            tree->fb = +1;
        else
            tree->fb = 0;

        if (auxB->fb == +1)
            auxA->fb = -1;
        else
            auxA->fb = 0;

        tree = auxB;
    }

    return tree;
}

void imprimirPrefixAVL(Node_avl *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->item);
        imprimirPrefixAVL(tree->left);
        imprimirPrefixAVL(tree->right);
    }
}

Node_avl *inserir(Node_avl *tree, int value, int *grown)
{
    Node_avl *auxA, *auxB;

    if (tree == NULL)
    {
        tree = criar(value);

        *grown = 1;
    }
    else if (value < tree->item)
    {
        tree->left = inserir(tree->left, value, grown);

        if (*grown)
        {
            switch (tree->fb)
            {
            case -1:
                tree->fb = 0;
                *grown = 0;
                break;
            case 0:
                tree->fb = +1;
                break;
            case +1:
                tree = rotateL(tree);
                tree->fb = 0;
                *grown = 0;
            }
        }
    }
    else if (value > tree->item)
    {
        tree->right = inserir(tree->right, value, grown);

        if (*grown)
        {
            switch (tree->fb)
            {
            case +1:
                tree->fb = 0;
                *grown = 0;
                break;
            case 0:
                tree->fb = -1;
                break;
            case -1:
                tree = rotateR(tree);
                tree->fb = 0;
                *grown = 0;
            }
        }
    }

    return tree;
}

void tree_to_vet(Node *tree, int tam, int vet[], int i)
{
    if (tree != NULL)
    {
        vet[i] = tree->item;
        i++;
        tree_to_vet(tree->left, tam, vet, i);
        tree_to_vet(tree->right, tam, vet, i);
    }
}

Node_avl *binario_para_avl(Node *tree_bi, Node_avl *tree, int tam)
{
    int vet[tam], pont_sum = 0;
    if (tree != NULL)
    {
        tree_to_vet(tree_bi, tam, vet, 0);
        tree = criar(vet[0]);
        for (int i = 1; i < tam; i++)
        {
            tree = inserir(tree, vet[i], &pont_sum);
        }
    }
    return tree;
}

int main()
{
    int items_tree, aux = 0;
    Node *tree_bi;
    Node_avl *tree;
    scanf("%d", &items_tree);
    scanf("%d", &aux);
    tree_bi = create_node(aux);
    tree = criar(0);
    for (int i = 1; i < items_tree; i++)
    {
        scanf("%d", &aux);
        tree_bi = insert(aux, tree_bi);
    }
    tree = binario_para_avl(tree_bi, tree, items_tree);
    imprimirPrefixAVL(tree);
    return 0;
}