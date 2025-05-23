#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *findMin(TreeNode *node)
{
    while (node && node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

TreeNode *deleteNode(TreeNode *tree, int value)
{
    if (tree == NULL)
        return NULL;

    if (value < tree->data)
    {

        tree->left = deleteNode(tree->left, value);
    }
    else if (value > tree->data)
    {

        tree->right = deleteNode(tree->right, value);
    }
    else
    {

        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            return NULL;
        }

        else if (tree->left == NULL)
        {
            TreeNode *temp = tree->right;
            free(tree);
            return temp;
        }

        else if (tree->right == NULL)
        {
            TreeNode *temp = tree->left;
            free(tree);
            return temp;
        }

        TreeNode *minRight = findMin(tree->right);
        tree->data = minRight->data;
        tree->right = deleteNode(tree->right, minRight->data);
    }
    return tree;
}

TreeNode *insertNode(TreeNode *tree, int value, int *error)
{
    if (tree != NULL && tree->data == value)
    {
        *error = 1;
        return tree;
    }

    if (tree == NULL)
    {

        TreeNode *newNode = malloc(sizeof(TreeNode));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (value < tree->data)
    {

        tree->left = insertNode(tree->left, value, error);
    }
    else if (value > tree->data)
    {

        tree->right = insertNode(tree->right, value, error);
    }

    return tree;
}

void printTree(TreeNode *root, int space)
{
    if (root == NULL)
        return;

    int indent = 5;
    space += indent;

    printTree(root->right, space);

    printf("\n");
    for (int i = indent; i < space; i++)
        printf(" ");
    printf("%d /\\\n", root->data);

    printTree(root->left, space);
}
void inorder(TreeNode *tree)
{
    if (tree == NULL)
        return;

    inorder(tree->left);
    printf("%d ", tree->data);
    inorder(tree->right);
}

void preOrder(TreeNode *tree)
{
    if (tree == NULL)
        return;

    printf("%d ", tree->data);
    preOrder(tree->left);
    preOrder(tree->right);
}

void postOrder(TreeNode *tree)

{
    if (tree == NULL)
        return;

    postOrder(tree->left);
    postOrder(tree->right);
    printf("%d ", tree->data);
}
void freeTree(TreeNode *tree)
{
    if (tree == NULL)
    {
        return;
    }
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}
int main()
{
    int error = 0;
    TreeNode *testTree = NULL;

    // Insert nodes into the tree
    int values[] = {55, 58, 23, 6, 9, 7, 15, 25, 75, 8, 49, 10, 42, 5, 61};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
    {
        testTree = insertNode(testTree, values[i], &error);
    }

    if (error)
    {
        printf("Error: Duplicate value detected during insertion.\n");
        return 1; // Exit early due to insertion error
    }

    // Delete a specific node (value = 61)
    testTree = deleteNode(testTree, 61);

    // Visual Tree
    printf("\n Binary Search Tree (Visual View):\n");
    printTree(testTree, 0);

    // Traversals
    printf("\n\n In-order Traversal:\n");
    inorder(testTree);
    printf("\n");

    printf("\n Pre-order Traversal:\n");
    preOrder(testTree);
    printf("\n");

    printf("\n Post-order Traversal:\n");
    postOrder(testTree);
    printf("\n");

    // Free memory
    freeTree(testTree);
    printf("\n Memory successfully freed.\n");

    return 0;
}
