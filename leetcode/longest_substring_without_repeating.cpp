class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0; // Maximum length found so far
        int i = 0, j = 0; // Sliding window pointers
        unordered_map<char, int> mp; // Map to store character frequencies

        while (j < s.length()) {
            mp[s[j]]++; // Add current character to window

            // If map size equals window size, all characters are unique
            if (mp.size() == j - i + 1) {
                mx = mx > j - i + 1 ? mx : j - i + 1; // Update maximum length
            }
            // If map size is less than window size, we have duplicates
            else if (mp.size() < j - i + 1) {
                // Shrink window from left until all characters are unique
                while (mp.size() < j - i + 1) {
                    mp[s[i]]--; // Decrease frequency of left character
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]); // Remove character if frequency becomes 0
                    }
                    i++; // Move left boundary
                }
            }
            j++; // Expand window
        }
        return mx;
    }
};