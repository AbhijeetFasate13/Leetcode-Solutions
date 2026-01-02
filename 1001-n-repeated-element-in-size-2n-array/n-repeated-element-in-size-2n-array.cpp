class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        if (n == 2)
            return nums[0];
        int duplicate = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                duplicate = nums[i];
                break;
            }
        }
        if (duplicate != -1) {
            return duplicate;
        }

        if (nums[0] == nums[n - 1] or nums[0] == nums[n - 2]) {
            duplicate = nums[0];
        } else if (nums[1] == nums[n - 1] or nums[1] == nums[n - 2]) {
            duplicate = nums[1];
        }
        return duplicate;
    }
};