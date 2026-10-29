# DSA Programs in C

A collection of beginner-friendly **Data Structures and Algorithms (DSA)** programs written in C. Each source file is a standalone program.

## Program list

| No. | Program | Source file |
| ---: | --- | --- |
| 1 | Linear Search | [linear_search.c](linear_search.c) |
| 2 | Bubble Sort | [bubble_sort.c](bubble_sort.c) |
| 3 | Polynomial Addition Using Arrays | [polynomial_addition_array.c](polynomial_addition_array.c) |
| 4 | Polynomial Addition Using Structures | [polynomial_addition_structure.c](polynomial_addition_structure.c) |
| 5 | Sparse Matrix (Triplet Representation) | [sparse_matrix.c](sparse_matrix.c) |
| 6 | Stack Operations | [stack_operations.c](stack_operations.c) |
| 7 | Linear Queue Operations | [queue_operations.c](queue_operations.c) |
| 8 | Circular Queue Operations | [circular_queue.c](circular_queue.c) |
| 9 | Infix to Postfix Conversion | [infix_to_postfix.c](infix_to_postfix.c) |
| 10 | Postfix Evaluation | [postfix_evaluation.c](postfix_evaluation.c) |
| 11 | Singly Linked List Operations | [singly_linked_list.c](singly_linked_list.c) |
| 12 | Doubly Linked List Operations | [doubly_linked_list.c](doubly_linked_list.c) |
| 13 | Binary Search Tree (Insertion, Search, Inorder Traversal) | [binary_search_tree.c](binary_search_tree.c) |
| 14 | Breadth-First Search (BFS) | [breadth_first_search.c](breadth_first_search.c) |
| 15 | Depth-First Search (DFS) | [depth_first_search.c](depth_first_search.c) |
| 16 | Selection Sort | [selection_sort.c](selection_sort.c) |
| 17 | Insertion Sort | [insertion_sort.c](insertion_sort.c) |
| 18 | Merge Sort | [merge_sort.c](merge_sort.c) |

## Compile and run

Install GCC, then compile a source file and run the executable.

**Linux / macOS**
```bash
gcc -std=c11 -Wall -Wextra -pedantic linear_search.c -o linear_search
./linear_search
```

**Windows (MinGW GCC)**
```bash
gcc -std=c11 -Wall -Wextra -pedantic linear_search.c -o linear_search.exe
linear_search.exe
```

Replace `linear_search.c` and the executable name with the program you want to run. Compile each file separately because each program has its own `main()`.

## Notes

- Binary search expects the input array to be sorted in ascending order.
- The graph traversal programs use an adjacency matrix and vertex numbers starting at `0`.
- The polynomial programs have different input formats: coefficients by degree for the array version, and coefficient/exponent pairs for the structure version.
- These examples are intended for learning. Read the prompts and constraints before entering data.
