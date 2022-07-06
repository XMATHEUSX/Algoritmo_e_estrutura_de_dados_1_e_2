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

void tree_is_avl(Node *tree, int *is_avl)
{
    if (tree != NULL)
    {
        if (tree->left != NULL && tree->right != NULL)
        {
            tree_is_avl(tree->left, is_avl);
            tree_is_avl(tree->right, is_avl);
        }
        else if (tree->left != NULL && tree->right == NULL)
        {
            if (tree->left->right != NULL || tree->left->left != NULL)
            {
                *is_avl = 0;
            }
        }
        else if (tree->left == NULL && tree->right != NULL)
        {
            if (tree->right->right != NULL || tree->right->left != NULL)
            {
                *is_avl = 0;
            }
        }
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
    int items_tree, aux = 0, *is_avl, pont = 1;
    Node *tree;
    is_avl = &pont;
    scanf("%d", &items_tree);
    scanf("%d", &aux);
    tree = create_node(aux);
    for (int i = 1; i < items_tree; i++)
    {
        scanf("%d", &aux);
        tree = insert(aux, tree);
    }
    tree_is_avl(tree, is_avl);
    printf("%d", pont);
    free_tree(tree);
    return 0;
}
