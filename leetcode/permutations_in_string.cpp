class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool flag = false;
        unordered_map<char, int> mp;
        mp.clear();

        int i = 0, j = 0, count = 0;

        for(auto x: s1) {
            mp[x]++;
        }

        count = mp.size();

        while(j < s2.length()) {
            char ch = s2[j];
            
            if(mp.find(ch) != mp.end()) {
                mp[ch]--;
                if(mp[ch] == 0) {
                    count--;
                }
            }
            if(j - i + 1 < s1.length()) {
                j++;
            } else if(j - i + 1 == s1.length()) {
                if(count == 0) {
                    return !flag;
                }

                char temp = s2[i];
                if(mp.find(temp) != mp.end()) {
                    mp[temp]++;
                    if(mp[temp] == 1) {
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return flag;
    }
};