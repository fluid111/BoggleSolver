# BoggleSolver
to compile the file 
g++ main.cpp trie.cpp boggle_solver.cpp support.cpp board.cpp -o boggle_solver.exe

to run the file 
in windows
boggle_solver.exe

Time Complexity

Trie- O(m)
m - length of words

for n words in the dictionary - O(n.m)
n - numbers of words


DFS Traversal :
-The board has N*N cells
-Each cell starts a DFS search.
-DFS explores at most 8 directions per step.
The worst-case DFS time complexity is 
𝑂
(
8
min
⁡
(
𝑁
2
,
𝑚
)
)
O(8 
min(N 
2
 ,m)
 ).
 Since we start DFS from each cell, total DFS complexity is 
𝑂
(
𝑁
2
⋅
8
min
⁡
(
𝑁
2
,
𝑚
)
)
O(N 
2
 ⋅8 
min(N 
2
 ,m)
 ).

Finding Words:
-Each DFS call checks if a word is in the Trie.
-If we visit each cell once and perform DFS, the worst-case time complexity is 
𝑂
(
𝑅
𝐶
⋅
8
min
⁡
(
𝑅
𝐶
,
𝑚
)
)
O(RC⋅8 
min(RC,m)
 ).
Final Time Complexity
O(n⋅m+N 
2
 ⋅8 
min(N 
2
 ,m)
 )


Space Complexity
Trie Storage- O(n.m)
n- number of word 
m-length of word
  
𝑂
(
𝑛
⋅
𝑚
)
O(n⋅m).
Board Storage:

The board itself takes 
O(N^2)
N-size of board

Visited Matrix for DFS:
O(N^2)

Found Words:
O(n)
n- number of found words 


Final Space Complexity
O(n.m+N^2)