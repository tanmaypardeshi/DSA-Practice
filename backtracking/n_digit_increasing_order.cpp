// Given an integer N, print all the N digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).

// Example 1:

// Input:
// N = 1
// Output:
// 0 1 2 3 4 5 6 7 8 9
// Explanation:
// Single digit numbers are considered to be 
// strictly increasing order.

#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&, int, int);

int main() {
    int n;
    vector<int> ans;

    cout << "Enter n:- ";
    cin >> n;

    if (n == 1) {
        cout << "Answer is:- ";
        for (int i = 0; i < 10; i++) {
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }

    solve(ans, 0, n);

    cout << "Answer is:- ";
    for (const auto& num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

void solve(vector<int>& ans, int number, int n) {
    if (n == 0) {
        ans.push_back(number);
        return;
    }

    int start = (number % 10) + 1;

    for (int i = start; i <= 9; i++) {
        number = (number * 10) + i;
        solve(ans, number, n - 1);
        number = (number - i) / 10;
    }
}