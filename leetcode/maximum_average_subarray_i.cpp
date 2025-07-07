class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double mx_avg = INT_MIN;
        int i = 0, j = 0, sum = 0;

        while(j < n) {
            sum += nums[j];

            if(j - i + 1 < k) {
                j++;
            } else if(j - i + 1 == k) {
                double tmp_avg = (double) sum / k;
                mx_avg = max(mx_avg, tmp_avg);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return mx_avg;
    }
};