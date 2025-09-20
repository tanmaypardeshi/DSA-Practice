// Given a string s, find all possible palindromic partitions of the given string.
// Input:
// S = "geeks"
// Output:
// g e e k s
// g ee k s
// Explanation:
// All possible palindromic partitions
// are printed.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPalindrome(string&);
void solve(string&, vector<string>&, int);

vector<vector<string>> ans;

int main() {
    string str;
    vector<string> temp;

    cout << "Enter the value of str:- ";
    cin >> str;

    solve(str, temp, 0);

    cout << "Answers are:- " << endl;
    for (const auto& a : ans) {
        for (const auto& s : a) {
            cout << s << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

bool isPalindrome(string& str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void solve(string& str, vector<string>& temp, int index) {
    if (index == str.size()) {
        ans.push_back(temp);
        return;
    }

    string pal_str;

    for (int i = index; i < str.size(); i++) {
        pal_str += str[i];
        if (isPalindrome(pal_str)) {
            temp.push_back(pal_str);
            solve(str, temp, i + 1);
            temp.pop_back();
        }
    }
}