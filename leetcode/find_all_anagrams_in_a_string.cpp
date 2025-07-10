class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans; // Result vector to store starting indices of anagrams
        unordered_map<char, int> mp; // Map to store character frequencies of pattern
        int i = 0, j = 0, count = 0; // Sliding window pointers and unique character count

        // Build frequency map of the pattern
        for (auto x : p) {
            mp[x]++;
        }

        count = mp.size(); // Number of unique characters in pattern

        // Sliding window approach to find all anagram occurrences
        while (j < s.length()) {
            char ch = s[j];

            // If character is part of pattern, decrease its frequency
            if (mp.find(ch) != mp.end()) {
                mp[ch]--;
                if (mp[ch] == 0) {
                    count--; // One character frequency matched completely
                }
            }

            if (j - i + 1 < p.length()) {
                j++; // Window size less than pattern size, expand window
            }
            else if (j - i + 1 == p.length()) {
                // Window size equals pattern size
                if (count == 0) {
                    ans.push_back(i); // All character frequencies matched, found anagram
                }

                // Slide window: remove leftmost character
                char temp = s[i];
                if (mp.find(temp) != mp.end()) {
                    mp[temp]++; // Restore frequency count
                    if (mp[temp] == 1) {
                        count++; // Character frequency no longer matches
                    }
                }
                j++; // Move right boundary
                i++; // Move left boundary
            }
        }
        return ans;
    }
};