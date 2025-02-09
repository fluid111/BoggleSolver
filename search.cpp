#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <fstream>
#include "support.h"
#include "trie.h"

using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},  // Vertical and horizontal
                                     {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

class BoggleSolver {
public:
    vector<vector<char>> board;
    Trie trie;
    unordered_set<string> found_words;
    int rows, cols;

    BoggleSolver(vector<vector<char>>& boggle_board, vector<string>& dictionary) {
        board = boggle_board;
        rows = board.size();
        cols = board[0].size();

        for (string& word : dictionary) {
            toLowercase(word);
            trie.insertKey(word);  // Insert each word into the Trie
        }
    }

    void dfs(int i, int j, string path, Trie* node, vector<vector<bool>>& visited) {
        if (node == nullptr) return;
    
        if (node->wordEnd) {
            found_words.insert(path);
            node->wordEnd = false;  // Prevent duplicate words
        }
    
        visited[i][j] = true;
    
        for (auto& dir : directions) {
            int x = i + dir.first;
            int y = j + dir.second;
    
            if (x >= 0 && x < rows && y >= 0 && y < cols && !visited[x][y]) {
                char ch = board[x][y];
                int index = ch - 'a';
    
                if (node->child[index] != nullptr) {
                    dfs(x, y, path + ch, node->child[index], visited);
                }
            }
        }
    
        visited[i][j] = false;
    }

    unordered_set<string> findWords() {
        found_words.clear();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                char ch = board[i][j];
                int index = ch - 'a';
    
                if (trie.child[index] != nullptr) {
                    dfs(i, j, string(1, ch), trie.child[index], visited);
                }
            }
        }
        return found_words;
    }
};


vector<string> loadDictionary(const string& filename) {
    vector<string> dictionary;
    ifstream file(filename);
    string word;
    
    if (file.is_open()) {
        while (file >> word) {
            dictionary.push_back(word);
        }
        file.close();
    } else {
        cerr << "Error: Could not open dictionary file." << endl;
    }
    
    return dictionary;
}


int main() {
    vector<vector<char>> board = {
        {'t', 't', 'o','i'},
        {'v', 'e', 'd', 't'},
        {'g', 'h', 'e', 'f'},
        {'t', 'u', 'n', 'y'}
    };

    // vector<string> dictionary = {"oath", "pea", "eat", "rain"};

    vector<string> dictionary = loadDictionary("dictionary1.txt");

    BoggleSolver solver(board, dictionary);
    unordered_set<string> found = solver.findWords();

    cout << "Found words:\n";
    for (const auto& word : found) {
        cout << word << endl;
    }

    return 0;
}
