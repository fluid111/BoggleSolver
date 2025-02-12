# BoggleSolver
This project is a Boggle solver implemented in C++. It uses a Trie data structure for efficient dictionary storage and Depth-First Search (DFS) to find all valid words on the Boggle board.

Compilation
To compile the program, use the following command:

g++ main.cpp trie.cpp boggle_solver.cpp support.cpp board.cpp -o boggle_solver.exe

Execution
After compilation, run the program as follows:

On Windows:

boggle_solver.exe

Time Complexity

Trie- O(m)
m - length of words

for n words in the dictionary - O(n.m)
n - numbers of words


DFS Traversal :
-The board has N*N cells
-For each cell, a DFS is initiated, which explores up to 8 directions .
-The maximum depth of DFS is the length of the longest word in the Trie, which is m.
-The worst-case time complexity for DFS from a single cell is O(8^m)
⁡-The total DFS complexity is O(n^2.8^m)

Finding Words:
-For each of the N^2 cells, the program performs a DFS with a complexity of O(8^m).
-During the DFS, the program performs O(m) Trie lookups for each path.
-Time complexity for finding words is:
O( N ^2 . 8 ^m .m)


Final Time Complexity
O( n⋅m + N^2 ⋅ 8^m )


Space Complexity

Trie Storage- O(n.m)
n- number of word 
m-length of word
O(n⋅m).

Board Storage:

The board itself is stored as a 2D array of size N * N
O(N^2)
N-size of board

Visited Matrix for DFS:
Visited matriz ias of size N * N
O(N^2)

Found Words:
O(n)
n- number of found words 


Final Space Complexity
O( n.m + N^2 )



flowchart TD
    A[Start] --> B[Read Board Size N * N]
    B --> C[Read Board Characters]
    C --> D[Display Board]
    D --> E[Load Dictionary]
    E --> F[Open dictionary.txt]
    F --> G[Read All Words]
    G --> H[Store Words in Dictionary List]
    H --> I[Initialize BoggleSolver]
    I --> J[Store Board and Dictionary in BoggleSolver]
    J --> K[Convert Dictionary Words to Lowercase]
    K --> L[Insert Words into Trie]
    L --> M[Initialize Found Words Set and Visited Matrix]
    M --> N[Iterate Over Each Cell (i, j) in Board]
    N --> O{"Is board[i][j] in Trie Root?"}
    O -->|Yes| P[Start DFS at (i, j)]
    O -->|No| N
    P --> Q[Append board[i][j] to Current Path]
    Q --> R[Mark Visited[i][j] = True]
    R --> S{"Is Current Path a Valid Word in Trie?"}
    S -->|Yes| T[Add Word to Found Words Set]
    S -->|No| U[Explore 8 Directions]
    T --> U
    U --> V{"Is Next Cell (x, y) Within Bounds AND Not Visited?"}
    V -->|Yes| W{"Is board[x][y] in Next Trie Node?"}
    W -->|Yes| X[Recursively Continue DFS at (x, y)]
    W -->|No| V
    V -->|No| Y[Backtrack: Reset Visited[i][j] = False]
    X --> Y
    Y --> N
    N --> Z[Print All Found Words]
    Z --> AA[End]
    
Requirements
C++ compiler (e.g., g++).

A dictionary file named dictionary.txt in the same directory as the executable.

