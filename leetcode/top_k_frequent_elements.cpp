class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq.clear();

        for(auto x: nums) {
            freq[x]++;
        }
        
        priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int>>> min_heap;
        vector<int> ans;
        for(const auto &x : freq) {
            min_heap.push({x.second, x.first});

            while(min_heap.size() > k) {
                min_heap.pop();
            }
        }

        while(min_heap.size() > 0) {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};