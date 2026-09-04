class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixMax(n), suffixMin(n);

        prefixMax[0] = nums[0], suffixMin[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(nums[i], prefixMax[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (prefixMax[i] - suffixMin[i] <= k) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};