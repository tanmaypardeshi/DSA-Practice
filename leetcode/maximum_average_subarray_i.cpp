class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double mx_avg = INT_MIN; // Maximum average found so far
        int i = 0, j = 0, sum = 0; // Sliding window pointers and current sum

        while (j < n) {
            sum += nums[j]; // Add current element to window sum

            if (j - i + 1 < k) {
                j++; // Window size less than k, just expand
            }
            else if (j - i + 1 == k) {
                // Window size equals k, calculate average and update maximum
                double tmp_avg = (double)sum / k;
                mx_avg = max(mx_avg, tmp_avg);

                sum -= nums[i]; // Remove leftmost element from sum
                i++; // Slide window: move left boundary
                j++; // Slide window: move right boundary
            }
        }
        return mx_avg;
    }
};