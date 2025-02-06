#include <iostream>
#include <fstream>
#include "search.h"
#include "trie.h"

using namespace std;

int main() {
    // Load dictionary from a file
    ifstream file("dictionary.txt");
    vector<string> dictionary;
    string word;

    while (getline(file, word)) {
        dictionary.push_back(word);
    }

    // Example Boggle board
    vector<vector<char>> board = {
        {'t', 'h', 'i', 's'},
        {'w', 'a', 't', 's'},
        {'o', 'a', 'h', 'g'},
        {'f', 'g', 'd', 't'}
    };

    // Solve Boggle
    BoggleSolver solver(board, dictionary);
    unordered_set<string> wordsFound = solver.findWords();

    // Print found words
    cout << "Words Found:" << endl;
    for (const string& word : wordsFound) {
        cout << word << endl;
    }

    return 0;
}
