class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long total = k;
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            if (nums[i] <= total) {
                total++;
                sum += nums[i];
            }
        }

        return (total * (total + 1)) / 2 - sum;
    }
};