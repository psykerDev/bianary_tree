# 🌳 Binary Search Tree in C

This is a C project that implements a **Binary Search Tree (BST)** for integers. It supports:

- Node insertion
- Node deletion (with all 3 standard cases)
- In-order, pre-order, and post-order traversals
- ASCII-based tree visualization
- Memory management (freeing nodes)

---

## 🧰 Features

### ✅ BST Operations

| Function         | Description                                                       |
| ---------------- | ----------------------------------------------------------------- |
| `insertNode`     | Inserts a value into the BST                                      |
| `deleteNode`     | Removes a node by value (handles all deletion cases)              |
| `inorder`        | Prints values in ascending order (Left → Node → Right)            |
| `preOrder`       | Prints values in Pre-order (Node → Left → Right)                  |
| `postOrder`      | Prints values in Post-order (Left → Right → Node)                 |
| `printTree`      | Displays the tree structure using ASCII indentation               |
| `freeTree`       | Frees all nodes recursively to clean up memory                    |
| `findMin`        | Helper function to find the smallest node in a given subtree      |

---

## 🧪 Example Program

The `main()` function:

1. Creates an empty tree.
2. Inserts 15 integers.
3. Deletes the value `61` from the tree.
4. Prints the tree visually.
5. Performs all three types of traversal.
6. Frees the tree's memory.

```c
int main()
{
    int error = 0;
    TreeNode *testTree = NULL;

    testTree = insertNode(testTree, 55, &error);
    testTree = insertNode(testTree, 58, &error);
    testTree = insertNode(testTree, 23, &error);
    testTree = insertNode(testTree, 6, &error);
    testTree = insertNode(testTree, 9, &error);
    testTree = insertNode(testTree, 7, &error);
    testTree = insertNode(testTree, 15, &error);
    testTree = insertNode(testTree, 25, &error);
    testTree = insertNode(testTree, 75, &error);
    testTree = insertNode(testTree, 8, &error);
    testTree = insertNode(testTree, 49, &error);
    testTree = insertNode(testTree, 10, &error);
    testTree = insertNode(testTree, 42, &error);
    testTree = insertNode(testTree, 5, &error);
    testTree = insertNode(testTree, 61, &error);

    testTree = deleteNode(testTree, 61);

    if (error)
        printf("Error: Duplicate value detected during insertion.\n");

    printTree(testTree, 0);

    printf("\n🧭 In-order Traversal:\n");
    inorder(testTree);
    printf("\n");

    printf("\n🧭 Pre-order Traversal:\n");
    preOrder(testTree);
    printf("\n");

    printf("\n🧭 Post-order Traversal:\n");
    postOrder(testTree);
    printf("\n");

    freeTree(testTree);
    printf("\n✅ Memory successfully freed.\n");

    return 0;
}
