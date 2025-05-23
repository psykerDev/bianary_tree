# 🌳 Binary Search Tree in C

This project is a complete implementation of a **Binary Search Tree (BST)** in C. It includes functions for inserting nodes, deleting nodes, visualizing the tree, traversing it in various orders, and freeing dynamically allocated memory.

## 📌 Features

- ✅ Insert values into the BST  
- ✅ Delete a node (supports all three deletion cases)  
- ✅ In-order, Pre-order, and Post-order traversals  
- ✅ Visual ASCII display of the tree structure  
- ✅ Duplicate value detection  
- ✅ Safe memory cleanup using `freeTree()`

## 🧠 Traversal Types

- **In-order (L → Node → R):** Returns values in sorted order.  
- **Pre-order (Node → L → R):** Good for copying the tree or building expressions.  
- **Post-order (L → R → Node):** Ideal for deleting the tree or evaluating expressions.

## 📂 File Structure


## 🛠️ How to Compile & Run

You can compile the program using `gcc`:

```bash
gcc main.c -o bst
./bst
make
./bst
📦 Binary Search Tree (Visual View):

          75 /\
     58 /\
          55 /\
               49 /\
                    42 /\
     25 /\
          23 /\
               15 /\
                    10 /\
                         9 /\
                              8 /\
                                   7 /\
                                        6 /\
                                             5 /\

🧭 In-order Traversal:
5 6 7 8 9 10 15 23 25 42 49 55 58 75 

🧭 Pre-order Traversal:
55 23 6 5 9 7 8 15 10 25 49 42 58 75 

🧭 Post-order Traversal:
5 8 7 10 15 9 6 42 49 25 23 75 58 55 

✅ Memory successfully freed.
