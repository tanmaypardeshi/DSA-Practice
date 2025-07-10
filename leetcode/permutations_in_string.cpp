class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool flag = false; // Return flag (false means not found, true means found)
        unordered_map<char, int> mp; // Map to store character frequencies of s1
        mp.clear();

        int i = 0, j = 0, count = 0; // Sliding window pointers and unique character count

        // Build frequency map of the pattern (s1)
        for (auto x : s1) {
            mp[x]++;
        }

        count = mp.size(); // Number of unique characters in s1

        // Sliding window approach to check if any permutation of s1 exists in s2
        while (j < s2.length()) {
            char ch = s2[j];

            // If character is part of s1, decrease its frequency
            if (mp.find(ch) != mp.end()) {
                mp[ch]--;
                if (mp[ch] == 0) {
                    count--; // One character frequency matched completely
                }
            }

            if (j - i + 1 < s1.length()) {
                j++; // Window size less than s1 length, expand window
            }
            else if (j - i + 1 == s1.length()) {
                // Window size equals s1 length
                if (count == 0) {
                    return !flag; // All character frequencies matched, found permutation (return true)
                }

                // Slide window: remove leftmost character
                char temp = s2[i];
                if (mp.find(temp) != mp.end()) {
                    mp[temp]++; // Restore frequency count
                    if (mp[temp] == 1) {
                        count++; // Character frequency no longer matches
                    }
                }
                i++; // Move left boundary
                j++; // Move right boundary
            }
        }
        return flag; // No permutation found, return false
    }
};