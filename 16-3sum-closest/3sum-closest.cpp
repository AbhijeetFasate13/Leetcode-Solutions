class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int minDiff = INT_MAX, ans;
        int n = nums.size(), j, k;
        for (int i = 0; i < n - 2; i++) {
            j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                }
                if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    return sum;
                }
            }
        }
        return ans;
    }
};