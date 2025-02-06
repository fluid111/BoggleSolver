#ifndef BOGGLE_SOLVER_H
#define BOGGLE_SOLVER_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include "Trie.h"

using namespace std;

class BoggleSolver {
private:
    int rows, cols;
    vector<vector<char>> board;
    Trie trie;
    unordered_set<string> found_words;

    // Directions for 8 neighboring cells
    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1},  {1, 0}, {1, 1}
    };

    // DFS function
    void dfs(int i, int j, string path, Trie* node, vector<vector<bool>>& visited);

public:
    // Constructor
    BoggleSolver(vector<vector<char>>& boggle_board, const string& dictionary);

    // Function to find words in the board
    unordered_set<string> findWords();
};

#endif // BOGGLE_SOLVER_H
