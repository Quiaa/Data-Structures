# Data Structures and Algorithms in C

This repository contains a collection of common data structures and algorithms implemented in the C programming language. Each implementation is self-contained in a single file and includes a `main` function for demonstration purposes.

## Implementations

Here is a list of the data structures and algorithms available in this repository.

### Data Structures

*   **AVL Tree**: A self-balancing binary search tree. (`avltree.c`)
*   **Doubly Linked List**: A linked list where each node has a pointer to the next and previous nodes. (`doublelinkl.c`)
*   **Dynamic Array**: An array that can grow in size. (`arraydynamic.c`, `dynamic_array.c`)
*   **Heap**: A specialized tree-based data structure that satisfies the heap property. (`heap.c`)
*   **Linked List**: A linear collection of data elements whose order is not given by their physical placement in memory. (`linkedlist.c`, `datas.c`)
*   **Priority Queue**: An abstract data type that behaves like a normal queue but where each element has a "priority". (`priorityq.c`)
*   **Queue**: A First-In-First-Out (FIFO) data structure. (`queue.c`)
*   **Stack**: A Last-In-First-Out (LIFO) data structure. (`stack.c`, `stacks.c`)

### Algorithms

*   **Binary Search**: An efficient algorithm for finding an item from a sorted list of items. (`binarysearch.c`)
*   **Infix to Postfix Conversion**: An algorithm to convert an infix expression to a postfix expression. (`infixtopostfix.c`, `intopost.c`)
*   **Parentheses Checker**: A program to check if the parentheses in an expression are balanced. (`parantheseschecker.c`)
*   **Postfix Expression Evaluation**: An algorithm to evaluate a postfix expression. (`postfixeva.c`)
*   **Reverse Linked List**: A function to reverse a linked list. (`reversell.c`, `reverse.c`)

## How to Compile and Run

Each file is self-contained and can be compiled using a C compiler like GCC.

To compile a file, run the following command in your terminal:

```bash
gcc <filename>.c -o <output_filename>
```

For example, to compile the linked list implementation:

```bash
gcc linkedlist.c -o linkedlist
```

To run the compiled program:

```bash
./<output_filename>
```

For example:

```bash
./linkedlist
```

## Contributing

Feel free to fork this repository and contribute by submitting a pull request. You can also open an issue to report bugs or suggest new features.
