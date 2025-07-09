class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int mx = 0, num_zeroes = 0;

        int i = 0, j = 0;

        while(j < nums.size()) {
            if (nums[j] == 0) {
                num_zeroes++;
            }
            
            // Shrink window if num_zeroes > k
            while (num_zeroes > k) {
                if (nums[i] == 0) {
                    num_zeroes--;
                }
                i++;
            }
            
            // Update max length for valid window
            mx = max(mx, j - i + 1);
            j++;
        }
        return mx;
    }
};