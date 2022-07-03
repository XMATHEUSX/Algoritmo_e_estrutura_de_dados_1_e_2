#include <stdio.h>

struct Pointer
{
    int item;
    int fb;
    struct Pointer *left;
    struct Pointer *right;
} typedef Node;

Node *criar(int item)
{
    Node *tree = (Node *)malloc(sizeof(Node));

    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

static Node *rotateL(Node *tree)
{
    Node *auxA = tree->left, *auxB;

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

static Node *rotateR(Node *tree)
{
    Node *auxA = tree->right, *auxB;

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
        auxA->left = auxB->right;
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

Node *inserir(Node *tree, int value, int *grown)
{
    Node *auxA, *auxB;

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

void sum_factor_bal(Node *tree, int *sum_fb)
{
    if (tree != NULL)
    {
        sum_factor_bal(tree->left, sum_fb);
        printf("%d - %d\n", tree->fb, tree->item);
        if (tree->fb <= 2 && tree->fb >= -2)
        {
            *sum_fb += tree->fb;
        }
        sum_factor_bal(tree->right, sum_fb);
    }
}

int main()
{
    int items_tree, aux = 0, *is_avl, pont = 0, *sum_fb, pont_sum = 0;
    Node *tree;
    is_avl = &pont;
    sum_fb = &pont_sum;
    scanf("%d", &items_tree);
    scanf("%d", &aux);
    tree = criar(aux);
    for (int i = 1; i < items_tree; i++)
    {
        scanf("%d", &aux);
        tree = inserir(tree, aux, is_avl);
    }
    sum_factor_bal(tree, sum_fb);
    printf("%d", pont_sum);
    return 0;
}
