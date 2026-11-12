class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1, incLen = 1, decLen = 1;

        for (int i = 1; i < n; i++) {
            incLen = nums[i] > nums[i - 1] ? incLen + 1 : 1;
            decLen = nums[i] < nums[i - 1] ? decLen + 1 : 1;
            ans = max({ans, incLen, decLen});
        }

        return ans;
    }
};