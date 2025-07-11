#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, t;

    cout << "Enter string 1:- "; // Prompt for input string s
    cin >> s; // Read string s

    cout << "Enter string 2:- "; // Prompt for input string t
    cin >> t; // Read string t

    int i = 0, j = 0, count = 0, start = 0; // Initialize sliding window pointers and variables
    int mn = INT_MAX; // Initialize minimum window length to maximum integer

    unordered_map<char, int> mp; // Create hash map to store character frequencies of t
    mp.clear(); // Clear the hash map

    for (auto x : t) { // Iterate through string t
        mp[x]++; // Count frequency of each character in t
    }

    count = mp.size(); // Store number of unique characters in t

    while (j < s.length()) { // Iterate through string s with j pointer
        if (mp.find(s[j]) != mp.end()) { // Check if current character is in t
            mp[s[j]]--; // Decrease frequency in map
            if (mp[s[j]] == 0) { // If frequency becomes 0
                count--; // Decrease count of required characters
            }
        }
        if (count == 0) { // If all required characters are found
            while (count == 0) { // Try to minimize window
                if (mp.find(s[i]) != mp.end()) { // If current character is in t
                    mp[s[i]]++; // Increase frequency in map
                    if (mp[s[i]] == 1) { // If frequency becomes 1
                        count++; // Increase count as character is needed again
                        if (mn > j - i + 1) { // Check if current window is smaller
                            mn = j - i + 1; // Update minimum window length
                            start = i; // Update start of minimum window
                        }
                    }
                }
                i++; // Shrink window from left
            }
        }
        j++; // Expand window from right
    }

    if (mn == INT_MAX) { // If no valid window found
        cout << "" << endl; // Output empty string
    }
    else {
        cout << s.substr(start, mn) << endl; // Output minimum window substring
    }

    return 0; // End program
}