#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include "Trie.h"
#include "search.h"

using namespace std;

int main() {
    // Define the Boggle board
    vector<vector<char>> board = {
        {'o', 'a', 'n'},
        {'e', 't', 'a'},
        {'i', 'h', 'k'},
        {'i', 'r', 'e'}
    };

    // Define the dictionary file path (You can replace this with your file path)
    string dictionaryFile = "dictionary.txt"; // Path to your dictionary file
    
    // Create the BoggleSolver object and load the dictionary
    BoggleSolver solver(board, dictionaryFile);

    // Find valid words on the Boggle board
    unordered_set<string> foundWords = solver.findWords();

    // Print the found words
    cout << "Found words in the Boggle board:" << endl;
    if (foundWords.empty()) {
        cout << "No valid words found!" << endl;
    } else {
        for (const string& word : foundWords) {
            cout << word << endl;
        }
    }

    return 0;
}
