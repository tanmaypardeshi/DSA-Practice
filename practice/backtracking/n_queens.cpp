// The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
// Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number.

// Examples :

// Input: 1
// Output: [1]
// Explaination: Only one queen can be placed 
// in the single cell available.
// Input: 4
// Output: [2 4 1 3 ] [3 1 4 2 ]
// Explaination: These are the 2 possible solutions.

#include <bits/stdc++.h>
using namespace std;

void solve(int, vector<vector<int>>&, int, vector<int>&);
bool isValid(int, int, vector<vector<int>>&, int);

vector<vector<int>> answer;

int main() {
    int n;

    cout << "Enter the value of n:- ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> temp;

    solve(0, board, n, temp);

    cout << "For n = " << n << ", solutions are:" << endl;
    if (answer.empty()) {
        cout << "No solutions exist." << endl;
    }
    else {
        for (const auto& solution : answer) {
            cout << "[ ";
            for (int val : solution) {
                cout << val << " ";
            }
            cout << "] ";
        }
        cout << endl;
        cout << "Total solutions: " << answer.size() << endl;
    }

    return 0;
}

void solve(int col_idx, vector<vector<int>>& board, int n, vector<int>& temp) {
    if (col_idx == n) {
        answer.push_back(temp);
        return;
    }

    for (int row_idx = 0; row_idx < n; row_idx++) {
        if (isValid(row_idx, col_idx, board, n)) {
            board[row_idx][col_idx] = 1;
            temp.push_back(row_idx + 1);
            solve(col_idx + 1, board, n, temp);
            temp.pop_back();
            board[row_idx][col_idx] = 0;
        }
    }
}

bool isValid(int row_idx, int col_idx, vector<vector<int>>& board, int n) {
    for (int i = 0; i < col_idx; i++) {
        if (board[row_idx][i] == 1) {
            return false;
        }
    }

    int i = row_idx;
    int j = col_idx;

    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }

    i = row_idx;
    j = col_idx;

    while (i < n && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}