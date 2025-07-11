class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0, j = 0, count = 0, start = -1;
        int mn = INT_MAX;

        unordered_map<char, int> mp;
        mp.clear();

        for (auto x : t) {
            mp[x]++;
        }

        count = mp.size();

        while (j < s.length()) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    count--;
                }
            }
            if (count == 0) {
                while (count == 0) {
                    if (mp.find(s[i]) != mp.end()) {
                        mp[s[i]]++;
                        if (mp[s[i]] == 1) {
                            count++;
                            if (mn > j - i + 1) {
                                mn = j - i + 1;
                                start = i;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        return start == -1 ? "" : s.substr(start, mn);
    }
};