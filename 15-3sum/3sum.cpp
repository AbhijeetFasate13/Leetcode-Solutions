class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        int n = nums.size(), l, r, target, a, b;
        for (int i = 0; i < n - 2; i++) {
            if (!ans.empty() and nums[i] == ans.back()[0])
                continue;
            l = i + 1, r = n - 1;
            target = -nums[i];
            while (l < r) {
                a = nums[l], b = nums[r];
                int sum = a + b;
                if (sum == target) {
                    while (l < r and nums[l] == a) {
                        l++;
                    }
                    while (r > l and nums[r] == b) {
                        r--;
                    }
                    ans.push_back({nums[i], a, b});
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};