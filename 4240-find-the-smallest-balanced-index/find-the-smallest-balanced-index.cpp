class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefixSum(n + 1, 0);
        vector<long long> suffixProd(n + 1, 1);

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int start = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (__builtin_mul_overflow(suffixProd[i + 1], nums[i],
                                       &suffixProd[i])) {
                start = i;
                break;
            }

            start = i;

            if (suffixProd[i] >= prefixSum.back()) {
                break;
            }
        }

        for (int i = start; i < n; i++) {
            long long leftSum = prefixSum[i];
            long long rightProd = suffixProd[i + 1];

            if (leftSum == rightProd) {
                return i;
            }
        }

        return -1;
    }
};