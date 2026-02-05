class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> best(k, LLONG_MAX);
        best[0] = 0;

        long long prefix = 0;
        long long ans = LLONG_MIN;

        for (int i = 1; i <= n; i++) {

            prefix += nums[i - 1];

            int mod = i % k;

            if (best[mod] != LLONG_MAX) {
                ans = max(ans, prefix - best[mod]);
            }

            best[mod] = min(best[mod], prefix);
        }

        return ans;
    }
};
