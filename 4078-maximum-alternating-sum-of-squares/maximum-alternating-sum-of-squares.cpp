class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
             [&](const int& a, const int& b) { return abs(a) < abs(b); });
        int n = nums.size();
        long long sum = n & 1 ? nums[n / 2] * nums[n / 2] : 0;
        for (int i = 0; i < n / 2; i++) {
            sum += nums[n - i - 1] * nums[n - i - 1] - nums[i] * nums[i];
        }
        return sum;
    }
};