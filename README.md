# BoggleSolver
to compile the file 
g++ main.cpp trie.cpp boggle_solver.cpp -o boggle_solver.exe

to run the file 
in windows
boggle_solver.exe

Time Complexity

Trie- O(m)
m - length of words

for n words in the dictionary - O(n.m)
n - numbers of words


DFS Traversal :
The board has N*N cells

Finding Words:

Final Time Complexity


Space Complexity
Trie Storage- O(n.m)
n-
m-
Board Storage:

The board itself takes 
O(N.N)
N-size of board

Visited Matrix for DFS:
O(N.N)

Found Words:
O(n)
n- number of found words 


Final Space Complexity
O(n.m+N)