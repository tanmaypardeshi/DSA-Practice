// Given a string s, find the length of the longest substring without duplicate characters.

#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;

    cout << "Enter string:- ";
    cin >> str;

    // Initialize variables: mx for max length, i/j for window boundaries
    int mx = INT16_MIN, i = 0, j = 0;
    unordered_map<char, int> mp; // Map to store frequency of characters in current window

    while (j < str.length()) {
        mp[str[j]]++; // Add current character to window

        // If map size equals window size, all characters are unique
        if (mp.size() == j - i + 1) {
            mx = max(mx, j - i + 1); // Update maximum length
        }
        // If map size is less than window size, we have duplicates
        else if (mp.size() < j - i + 1) {
            // Shrink window from left until all characters are unique
            while (mp.size() < j - i + 1) {
                mp[str[i]]--; // Decrease frequency of left character
                if (mp[str[i]] == 0) {
                    mp.erase(str[i]); // Remove character if frequency becomes 0
                }
                i++; // Move left boundary
            }
        }
        j++; // Expand window
    }
    cout << "Length of maximum substring is: " << mx << endl;
    return 0;
}