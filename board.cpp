#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> inputBoard(int &size) {
    cout << "Enter the size of board (n x n): ";
    cin >> size;

    vector<vector<char>> board(size, vector<char>(size));

    cout << "Enter the board letters:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> board[i][j];
        }
    }

    return board;
}

void printBoard(const vector<vector<char>>& board) {
    cout << "Entered board:\n";
    for (const auto& row : board) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// int main() {
    // int size;
//     vector<vector<char>> board = inputBoard(size);

//     printBoard(board);

//     return 0;
// }
