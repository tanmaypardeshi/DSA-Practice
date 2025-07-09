// You are given a string s consisting only lowerc case alphabets and an integer k. 
// Your task is to find the length of the longest substring that contains exactly k distinct characters.

#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;

    cout << "Enter string:- ";
    cin >> str;

    int k;

    cout << "Enter k:- ";
    cin >> k;

    unordered_map<char, int> mp;
    mp.clear();

    int i = 0, j = 0, mx = INT16_MIN;

    while (j < str.length()) {
        mp[str[j]]++;

        if (mp.size() < k) {
            j++;
        }
        else if (mp.size() == k) {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (mp.size() > k) {
            while (mp.size() > k) {
                mp[str[i]]--;
                if (mp[str[i]] == 0) {
                    mp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
    }

    cout << "Maximum length of substring is " << mx << endl;

    return 0;
}