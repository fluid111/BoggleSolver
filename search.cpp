#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <fstream>
#include "search.h"
#include "support.h"
// class BoggleSolver {
// private:
    // DFS to explore the board
    void BoggleSolver::dfs(int i, int j, string path, Trie* node, vector<vector<bool>>& visited) {
        if (node->wordEnd) {
            found_words.insert(path);
            node->wordEnd = false; // Avoid duplicate entries
        }

        for (auto& dir : directions) {
            int x = i + dir.first;
            int y = j + dir.second;

            // Check if within bounds and not visited
            if (x >= 0 && x < rows && y >= 0 && y < cols && !visited[x][y]) {
                char ch = board[x][y];

                // Check if character exists in Trie
                int index = ch - 'a';
                if (node->child[index] != nullptr) {
                    visited[x][y] = true;
                    dfs(x, y, path + ch, node->child[index], visited);
                    visited[x][y] = false; // Backtrack
                }
            }
        }
    }

// public:
    BoggleSolver::BoggleSolver(vector<vector<char>>& boggle_board, const string& dictionary) {
        board = boggle_board;
        rows = board.size();
        cols = board[0].size();

        // Insert all words from the dictionary into the Trie
    //     for (const string& word : dictionary) {
    //         trie.insertKey(word);
    //     }
    // }

     ifstream file(dictionary);
        string word;
        
        while (getline(file, word)) {
            //passing word as a vector
            vector<string> tempWordVec;
            tempWordVec.push_back(word);
            toLowercase(tempWordVec);
            trie.insertKey(word);  // Insert each word into the Trie
        }
    }

    // Find all valid words on the board
    unordered_set<string> BoggleSolver::findWords() {
        found_words.clear();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Start DFS from every cell
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                char ch = board[i][j];

                int index = ch - 'a';
                if (trie.child[index] != nullptr) {
                    visited[i][j] = true;
                    dfs(i, j, string(1, ch), trie.child[index], visited);
                    visited[i][j] = false;
                }
            }
        }
        return found_words;
    }
// };
