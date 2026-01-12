class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> primeFactorCount;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 2; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    primeFactorCount.insert(j);
                }
                while (nums[i] % j == 0) {
                    nums[i] /= j;
                }
                if (nums[i] == 1)
                    break;
            }
            if (nums[i] > 1)
                primeFactorCount.insert(nums[i]);
        }
        return primeFactorCount.size();
    }
};