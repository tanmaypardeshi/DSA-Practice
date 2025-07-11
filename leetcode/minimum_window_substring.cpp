class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0, j = 0, count = 0, start = -1; // Initialize pointers and variables
        int mn = INT_MAX; // Store minimum window length

        unordered_map<char, int> mp; // Map to store character counts of t
        mp.clear();

        for (auto x : t) {
            mp[x]++; // Count each character in t
        }

        count = mp.size(); // Number of unique characters to match

        while (j < s.length()) { // Expand the window with j
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--; // Decrement count for current character
                if (mp[s[j]] == 0) {
                    count--; // One unique character matched
                }
            }
            if (count == 0) { // All characters matched
                while (count == 0) { // Try to shrink the window from left
                    if (mp.find(s[i]) != mp.end()) {
                        mp[s[i]]++; // Increment count for leftmost character
                        if (mp[s[i]] == 1) {
                            count++; // One unique character is now missing
                            if (mn > j - i + 1) {
                                mn = j - i + 1; // Update minimum window length
                                start = i; // Update start index
                            }
                        }
                    }
                    i++; // Move left pointer forward
                }
            }
            j++; // Move right pointer forward
        }
        return start == -1 ? "" : s.substr(start, mn); // Return result or empty string
    }
};