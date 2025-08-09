// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Example 1:


// Input:  board = [
//             ["5","3",".",".","7",".",".",".","."],
//             ["6",".",".","1","9","5",".",".","."],
//             [".","9","8",".",".",".",".","6","."],
//             ["8",".",".",".","6",".",".",".","3"],
//             ["4",".",".","8",".","3",".",".","1"],
//             ["7",".",".",".","2",".",".",".","6"],
//             [".","6",".",".",".",".","2","8","."],
//             [".",".",".","4","1","9",".",".","5"],
//             [".",".",".",".","8",".",".","7","9"]
//         ]

// Output: board = [
//             ["5","3","4","6","7","8","9","1","2"],
//             ["6","7","2","1","9","5","3","4","8"],
//             ["1","9","8","3","4","2","5","6","7"],
//             ["8","5","9","7","6","1","4","2","3"],
//             ["4","2","6","8","5","3","7","9","1"],
//             ["7","1","3","9","2","4","8","5","6"],
//             ["9","6","1","5","3","7","2","8","4"],
//             ["2","8","7","4","1","9","6","3","5"],
//             ["3","4","5","2","8","6","1","7","9"]
//         ]

#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<char>>&, int, int);
bool isValid(vector<vector<char>>&, int, int, char);
void printBoard(const std::vector<std::vector<char>>&);

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solve(board, 0, 0);

    printBoard(board);

    return 0;
}

bool solve(vector<vector<char>>& board, int row_idx, int col_idx) {
    if (row_idx == 9) {
        return true;
    }
    if (col_idx == 9) {
        return solve(board, row_idx + 1, 0);
    }

    if (board[row_idx][col_idx] != '.') {
        return solve(board, row_idx, col_idx + 1);
    }

    for (char i = '1'; i <= '9'; i++) {
        if (isValid(board, row_idx, col_idx, i)) {
            board[row_idx][col_idx] = i;
            bool result = solve(board, row_idx, col_idx + 1);
            if (result == true) {
                return true;
            }
        }
    }
    board[row_idx][col_idx] = '.';
    return false;
}

bool isValid(vector<vector<char>>& board, int row_idx, int col_idx, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col_idx] == num) {
            return false;
        }

        if (board[row_idx][i] == num) {
            return false;
        }

        if (board[(row_idx / 3) * 3 + i / 3][(col_idx / 3) * 3 + i % 3] == num) {
            return false;
        }
    }
    return true;
}

void printBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i != 0) {
            std::cout << "- - - - - - - - - - - -\n";
        }
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0 && j != 0) {
                std::cout << " | ";
            }
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}