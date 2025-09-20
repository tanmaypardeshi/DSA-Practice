// Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.

// Follow examples for better understanding.

// Example 1:

// Input: s = "catsanddog", n = 5 
// dict = {"cats", "cat", "and", "sand", "dog"}
// Output: (cats and dog)(cat sand dog)
// Explanation: All the words in the given 
// sentences are present in the dictionary

#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;

void solve(string&, int, vector<string>&, unordered_set<string>&);
vector<string> ans;


int main() {
    string s;
    vector<string> dict;
    int n1, n2;

    cout << "Enter string:- ";
    cin >> s;

    n1 = s.length();

    cout << "Enter the size of dict:- ";
    cin >> n2;

    for (int i = 0; i < n2; i++) {
        string temp;
        cout << "Enter word " << i + 1 << ":- ";
        cin >> temp;
        dict.push_back(temp);
    }

    unordered_set<string> dict_set;
    vector<string> temp;

    for (const auto& x : dict) {
        dict_set.insert(x);
    }

    solve(s, 0, temp, dict_set);

    cout << "Answers are:- " << endl;
    for (const auto& x : ans) {
        cout << x << endl;
    }

    return 0;
}

void solve(string& s, int start, vector<string>& temp, unordered_set<string>& dict_set) {
    if (start == s.length()) {
        string sentence = "";
        for (int j = 0; j < temp.size(); j++) {
            sentence += temp[j];
            if (j != temp.size() - 1) {
                sentence += " ";
            }
        }
        ans.push_back(sentence);
        return;
    }
    string word;
    for (int i = start; i < s.length(); i++) {
        word += s[i];
        if (dict_set.find(word) != dict_set.end()) {
            temp.push_back(word);
            solve(s, i + 1, temp, dict_set);
            temp.pop_back();
        }
    }
}

