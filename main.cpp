#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include "trie.h"
#include "search.h"
#include "support.h"
#include "board.h"


using namespace std;

int main() {
    // std::vector<std::vector<char>> board = {
    //     {'t', 't', 'o','i'},
    //     {'v', 'e', 'd', 't'},
    //     {'g', 'h', 'e', 'f'},
    //     {'t', 'u', 'n', 'y'}
    int size;
    // };
    std::vector<std::vector<char>> board;
    board = inputBoard(size);
    // cout<<"the given board";
    printBoard(board);
    // vector<string> dictionary = {"oath", "pea", "eat", "rain"};

    vector<string> dictionary = loadDictionary("dictionary.txt");

    BoggleSolver solver(board, dictionary);
    unordered_set<string> found = solver.findWords();

    cout << "Found words:\n";
    for (const auto& word : found) {
        cout << word << endl;
    }
    return 0;
}
