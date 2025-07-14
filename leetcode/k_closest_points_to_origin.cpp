typedef pair<int, vector<int>> pvi;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pvi> max_heap;
        vector<vector<int>> ans;
        for (const auto& pt : points) {
            int distance = pt[0]*pt[0] + pt[1]*pt[1];
            max_heap.push({distance, pt});

            while(max_heap.size() > k) {
                max_heap.pop();
            }
        }
        while(max_heap.size() > 0) {
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return ans;
    }
};