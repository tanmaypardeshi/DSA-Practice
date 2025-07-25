// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat 
// can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell 
// in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.

// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR

#include <bits/stdc++.h>
using namespace std;

struct Choice {
    char dname;
    int dx, dy;
};

void solve(int, int, int, vector<string>&, string&, vector<vector<int>>&, const vector<Choice>&);
bool isSolved(int, int, int);
bool isValid(int, int, int, const vector<vector<int>>&);

int main() {
    vector<vector<int>> arr{ {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };
    vector<Choice> choices = { {'U', -1, 0}, {'D', 1, 0}, {'L', 0, -1}, {'R', 0, 1} };
    vector<string> ans;
    string path = "";
    int n;

    cout << "Enter the value of n:- ";
    cin >> n;

    if (arr[0][0] == 1) {
        solve(0, 0, n, ans, path, arr, choices);
    }

    for (const auto& p : ans) {
        cout << p << endl;
    }

    return 0;
}

bool isSolved(int x, int y, int n) {
    return x == n - 1 && y == n - 1;
}
bool isValid(int x, int y, int n, const vector <vector<int>>& arr) {
    return x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1;
}

void solve(int x, int y, int n, vector<string>& ans, string& path, vector<vector<int>>& arr, const vector<Choice>& choices) {
    if (isSolved(x, y, n)) {
        ans.push_back(path);
        return;
    }

    for (const auto& choice : choices) {
        int x = x + choice.dx;
        int y = y + choice.dy;
        if (isValid(x, y, n, arr)) {
            arr[x][y] = 0;
            path.push_back(choice.dname);

            solve(x, y, n, ans, path, arr, choices);

            arr[x][y] = 1;
            path.pop_back();
        }
    }
}