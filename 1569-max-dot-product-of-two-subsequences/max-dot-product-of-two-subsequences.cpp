class Solution {
    vector<vector<int>> dp;
    int rec(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if (i == nums1.size() or j == nums2.size())
            return INT_MIN / 10;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = nums1[i] * nums2[j];
        return dp[i][j] = max({ans, ans + rec(i + 1, j + 1, nums1, nums2),
                               rec(i, j + 1, nums1, nums2),
                               rec(i + 1, j, nums1, nums2)});
    }

public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(), vector<int>(nums2.size(), -1));
        return rec(0, 0, nums1, nums2);
    }
};