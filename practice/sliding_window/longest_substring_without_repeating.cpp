// Given a string s, find the length of the longest substring without duplicate characters.

#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;

    cout << "Enter string:- ";
    cin >> str;

    int mx = INT16_MIN, i = 0, j = 0;
    unordered_map<char, int> mp;

    while (j < str.length()) {
        mp[str[j]]++;
        if (mp.size() == j - i + 1) {
            mx = max(mx, j - i + 1);
        }
        else if (mp.size() < j - i + 1) {
            while (mp.size() < j - i + 1) {
                mp[str[i]]--;
                if (mp[str[i]] == 0) {
                    mp.erase(str[i]);
                }
                i++;
            }
        }
        j++;
    }
    cout << "Length of maximum substring is: " << mx << endl;
    return 0;
}