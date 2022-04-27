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
    int items_tree, aux = 0, deepest = 0;
    Node *tree;
    scanf("%d", &items_tree);
    scanf("%d", &aux);
    tree = create_node(aux);
    for (int i = 1; i < items_tree; i++)
    {
        scanf("%d", &aux);
        tree = insert(aux, tree);
    }
    printf("%d", height_tree(tree, deepest));
    free_tree(tree);
    return 0;
}
