#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include "support.h"
#include "trie.h"

using namespace std;

class BoggleSolver {
public:
    vector<vector<char>> board;
    unordered_set<string> findWords();
    Trie trie;
    unordered_set<string> found_words;
    int rows, cols;
// private:

    BoggleSolver(std::vector<std::vector<char>>& boggle_board, std::vector<std::string>& dictionary);
    void dfs(int i, int j, std::string path, Trie* node, std::vector<std::vector<bool>>& visited);
};

std::vector<std::string> loadDictionary(const std::string& filename);

#endif
