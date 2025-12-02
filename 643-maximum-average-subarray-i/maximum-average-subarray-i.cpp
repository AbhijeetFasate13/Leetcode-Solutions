class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, l = 0;
        int n = nums.size();
        for (int r = 0; r < k; r++) {
            sum += nums[r];
        }
        double maxAvg = sum / (k * 1.0);
        for (int r = k; r < n; r++) {
            sum += nums[r];
            sum -= nums[l];
            l++;
            maxAvg = max(maxAvg, sum / (k * 1.0));
        }
        return maxAvg;
    }
};