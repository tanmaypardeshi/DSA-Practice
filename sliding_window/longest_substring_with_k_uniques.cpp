// You are given a string s consisting only lowercase alphabets and an integer k. 
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

    unordered_map<char, int> mp; // Map to store character frequencies in current window
    mp.clear();

    int i = 0, j = 0, mx = INT16_MIN; // Sliding window pointers and maximum length

    while (j < str.length()) {
        mp[str[j]]++; // Add current character to window

        if (mp.size() < k) {
            j++; // Less than k distinct characters, expand window
        }
        else if (mp.size() == k) {
            // Exactly k distinct characters, update maximum length
            mx = max(mx, j - i + 1);
            j++; // Continue expanding to find longer valid substrings
        }
        else if (mp.size() > k) {
            // More than k distinct characters, shrink window from left
            while (mp.size() > k) {
                mp[str[i]]--; // Decrease frequency of leftmost character
                if (mp[str[i]] == 0) {
                    mp.erase(str[i]); // Remove character if frequency becomes 0
                }
                i++; // Move left boundary
            }
            j++; // Continue with right boundary
        }
    }

    cout << "Maximum length of substring is " << mx << endl;

    return 0;
}