class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxm = *max_element(nums.begin(), nums.end());
        int minm = *min_element(nums.begin(), nums.end());
        return 1ll * k * (maxm - minm);
    }
};