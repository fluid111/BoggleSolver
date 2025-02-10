#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include "trie.h"
#include "search.h"
#include"support.h"

using namespace std;

int main() {
    std::vector<std::vector<char>> board = {
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
}
