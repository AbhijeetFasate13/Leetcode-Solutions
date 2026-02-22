class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = INT_MAX, ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum - target) < minDiff) {
                        minDiff = abs(sum - target);
                        ans = sum;
                        if (minDiff == 0) {
                            return ans;
                        }
                    }
                }
            }
        }
        return ans;
    }
};