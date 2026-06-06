class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans(n);
        int l = 0, r = totalSum;
        for (int i = 0; i < n; i++) {
            r -= nums[i];
            ans[i] = abs(l - r);
            l += nums[i];
        }
        return ans;
    }
};