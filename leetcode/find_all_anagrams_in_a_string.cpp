class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> mp;
        int i = 0, j = 0, count = 0;

        for(auto x : p) {
            mp[x]++;
        }

        count = mp.size();

        while(j < s.length()) {
            char ch = s[j];

            if(mp.find(ch) != mp.end()) {
                mp[ch]--;
                if(mp[ch] == 0) {
                    count--;
                }
            }

            if(j - i + 1 < p.length()) {
                j++;
            } else if(j - i + 1 == p.length()) {
                if(count == 0) {
                    ans.push_back(i);
                }
                char temp = s[i];
                if(mp.find(temp) != mp.end()) {
                    mp[temp]++;
                    if(mp[temp] == 1) {
                        count++;
                    }
                }
                j++;
                i++;
            }
        }
        return ans;
    }
};