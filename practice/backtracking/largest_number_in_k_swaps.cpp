// Given a string of digits, return the largest number in k swaps.

#include<bits/stdc++.h>
using namespace std;

void solve(string&, string&, int, int);

int main() {
    string num, ans;
    int k;

    cout << "Enter a number:- ";
    cin >> num;
    ans = num;

    cout << "Enter the number of swaps:- ";
    cin >> k;

    solve(num, ans, k, 0);

    cout << "Largest number after k swaps is:- " << ans << endl;

    return 0;
}

void solve(string& num, string& ans, int k, int start) {
    char max;
    // Base condition
    if (k == 0 || start == num.size()) {
        return;
    }

    for (const auto& x : num) {
        max = *max_element(num.begin() + start + 1, num.end());
    }

    for (int i = start + 1; i < num.size(); i++) {
        if (num[start] < num[i] && num[i] == max) {
            swap(num[start], num[i]);
            if (num.compare(ans) > 0) {
                ans = num;
            }
            solve(num, ans, k - 1, start + 1);
            swap(num[start], num[i]);

        }
    }
    solve(num, ans, k, start + 1);
}