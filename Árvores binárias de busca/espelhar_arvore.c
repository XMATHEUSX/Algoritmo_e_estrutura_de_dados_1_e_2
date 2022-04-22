/*
Implemente uma função que receba uma árvore binária de busca.
A função deverá trocar a subárvore esquerda pela direita de todos os nós da
árvore. Exemplo:

Em seguida, imprima o percurso simétrico (infixo) da árvore.

Input Format

Na primeira linha deve ser lido o número inteiro N, que é referente à
quantidade de nós da árvore binária de busca. Em seguida, em cada linha
deve ser lido um número inteiro para ser inserido como nó na árvore
(fazer isso até que N números sejam lidos).

Constraints

.

Output Format

Imprimir o valor da chave de cada nó folha em uma única linha.

Sample Input 0

8
4
2
6
1
3
5
10
8

Sample Output 0

10 8 6 5 4 3 2 1



*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define max2(a, b) a > b ? a : b

struct Node
{
    int item;
    struct Node *left;
    struct Node *right;
} typedef Node;

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

int height_tree(Node *tree, int deepest)
{
    int depth1, depth2;
    if (tree != NULL)
    {
        depth1 = max2(deepest, height_tree(tree->left, deepest));
        depth2 = max2(deepest, height_tree(tree->right, deepest));
        deepest = max2(depth1, depth2);
        if (tree->left == NULL && tree->right == NULL)
        {
            return deepest;
        }
        return (deepest + 1);
    }
    return NULL;
}

void number_leaf(Node *tree, int *leaf)
{
    if (tree != NULL)
    {
        number_leaf(tree->left, leaf);
        number_leaf(tree->right, leaf);
        if (tree->left == NULL && tree->right == NULL)
        {
            (*leaf)++;
        }
    }
}

int is_full(Node *tree)
{
    int pont, height, *leafs, elements;
    leafs = &pont;
    height = height_tree(tree, 0);
    number_leaf(tree, leafs);
    elements = pow(2, height);
    if (elements == pont)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void mirror_tree(Node *tree)
{
    if (tree != NULL)
    {
        Node *aux = (Node *)malloc(sizeof(Node));
        mirror_tree(tree->left);
        mirror_tree(tree->right);
        aux = tree->left;
        tree->left = tree->right;
        tree->right = aux;
    }
}

void printInfix(Node *tree)
{
    if (tree != NULL)
    {
        printInfix(tree->left);
        printf("%i ", tree->item);
        printInfix(tree->right);
    }
}
void free_tree(Node *tree)
{
    if (tree != NULL)
    {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}

int main()
{
    int items_tree, aux = 0;
    Node *tree;
    scanf("%d", &items_tree);
    scanf("%d", &aux);
    tree = create_node(aux);
    for (int i = 1; i < items_tree; i++)
    {
        scanf("%d", &aux);
        tree = insert(aux, tree);
    }
    mirror_tree(tree);
    printInfix(tree);
    free_tree(tree);
    return 0;
}
