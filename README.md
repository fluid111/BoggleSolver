# BoggleSolver
This project is a Boggle solver implemented in C++. It uses a Trie data structure for efficient dictionary storage and Depth-First Search (DFS) to find all valid words on the Boggle board.

## Compilation
To compile the program, use the following command:

`g++ main.cpp trie.cpp boggle_solver.cpp support.cpp board.cpp -o boggle_solver.exe`

## Execution
After compilation, run the program as follows:

On Windows:

`boggle_solver.exe`

## Time Complexity

### Trie- O(m)
m - length of words

for n words in the dictionary -  **O(n.m)**

n - numbers of words


### DFS Traversal :
The board has N*N cells

For each cell, a DFS is initiated, which explores up to 8 directions 

The maximum depth of DFS is the length of the longest word in the Trie, which is m

The worst-case time complexity for DFS from a single cell is **O(8^m)**

The total DFS complexity is **O(n^2.8^m)**

### Finding Words:
For each of the N^2 cells, the program performs a DFS with a complexity of **O(8^m)**

During the DFS, the program performs **O(m)** Trie lookups for each path

## Time complexity for finding words is:

**O( N ^2 . 8 ^m .m)**


### Final Time Complexity
**O( n⋅m + N^2 ⋅ 8^m )**


## Space Complexity

### Trie Storage -
n- number of word 

m-length of word

**O(n⋅m)**

### Board Storage:

The board itself is stored as a 2D array of size N * N

**O(N^2)**

N-size of board

### Visited Matrix for DFS:
Visited matriz ias of size N * N
**O(N^2)**

### Found Words:
**O(n)**
n- number of found words 


### Final Space Complexity
**O( n.m + N^2 )**




## Requirements
C++ compiler (e.g., g++).

A dictionary file named dictionary.txt in the same directory as the executable.

