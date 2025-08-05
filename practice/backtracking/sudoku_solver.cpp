// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

#include<bits/stdc++.h>
using namespace std;

bool solve(int, int, vector<vector<char>>&);
bool isValid(int, int, char, vector<vector<char>>&);
void printBoard(const vector<vector<char>>&);

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
    solve(0, 0, board);
    printBoard(board);

}

bool solve(int row_idx, int col_idx, vector<vector<char>>& board) {
    if(row_idx == 9) {
        return true;
    }

    if(col_idx == 9) {
        return solve(row_idx+1, 0, board);
    }

    if(board[row_idx][col_idx] != '.') {
        return solve(row_idx, col_idx+1, board);
    }

    for(char num = '1'; num <= '9'; num++) {
        if(isValid(row_idx, col_idx, num, board)) {
            board[row_idx][col_idx] = num;
            bool res = solve(row_idx, col_idx+1, board);
            if(res == true) {
                return res;
            }
        }
    }
    board[row_idx][col_idx] = '.';
    return false;
}

bool isValid(int row_idx, int col_idx, char num, vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++) {
        if(board[row_idx][i] == num) {
            return false;
        }
    }

    for(int i = 0; i < 9; i++) {
        if(board[i][col_idx] == num) {
            return false;
        }
    }

    int rc = (row_idx / 3) * 3;
    int cc = (col_idx / 3) * 3;
    for(int i = rc; i < rc + 3; i++) {
        for(int j = cc; j < cc + 3; j++) {
            if(board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << '\n';
    }
}