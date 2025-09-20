// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

void solve(string&, int, string&, unordered_map<char, string>&);

vector<string> ans;

int main() {
    string number;

    cout << "Enter number:- ";
    cin >> number;

    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    string temp;

    solve(number, 0, temp, mp);

    cout << "Combinations are:- " << endl;
    for (const auto& a : ans) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}

void solve(string& number, int start, string& temp, unordered_map<char, string>& mp) {
    if (start == number.size()) {
        ans.push_back(temp);
        return;
    }

    char ch = number[start];
    for (const auto& letter : mp[ch]) {
        temp.push_back(letter);
        solve(number, start + 1, temp, mp);
        temp.pop_back();
    }
}