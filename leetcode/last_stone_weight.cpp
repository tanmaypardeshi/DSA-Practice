class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        if(stones.size() == 1) {
            return stones[0];
        }
        for(const auto &stone: stones) {
            max_heap.push(stone);
        }
        while(max_heap.size() >= 2) {
            int y = max_heap.top();
            max_heap.pop();
            int x = max_heap.top();
            max_heap.pop();
            if(x == y) {
                continue;
            } else {
                max_heap.push(y-x);
            }
        }
        return max_heap.empty() ? 0 : max_heap.top();
    }
};