class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int mx = 0, num_zeroes = 0; // Maximum length and count of zeros in current window

        int i = 0, j = 0; // Sliding window pointers

        while (j < nums.size()) {
            // If current element is 0, increment zero count
            if (nums[j] == 0) {
                num_zeroes++;
            }

            // Shrink window from left if we have more than k zeros
            while (num_zeroes > k) {
                if (nums[i] == 0) {
                    num_zeroes--; // Remove zero from count
                }
                i++; // Move left boundary
            }

            // Update max length for current valid window (at most k zeros)
            mx = max(mx, j - i + 1);
            j++; // Expand window by moving right boundary
        }
        return mx;
    }
};