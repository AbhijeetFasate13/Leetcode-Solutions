class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int minMaxPairSum = nums[0] + nums[n - 1];
        for (int i = 1; i < n / 2; i++) {
            minMaxPairSum = max(minMaxPairSum, nums[i] + nums[n - i - 1]);
        }
        return minMaxPairSum;
    }
};