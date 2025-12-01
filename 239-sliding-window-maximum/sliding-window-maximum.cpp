class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxi = INT_MIN, idx = -1;
        int l = 0;
        int n = nums.size();
        vector<int> ans(n - k + 1);
        for (int r = 0; r < k; r++) {
            if (nums[r] >= maxi) {
                maxi = nums[r];
                idx = r;
            }
        }
        ans[l] = maxi;
        for (int r = k; r < n; r++) {
            if (nums[r] >= maxi) {
                maxi = nums[r];
                idx = r;
                l++;
                ans[l] = maxi;
                continue;
            }
            if (idx == l) {
                maxi = INT_MIN;
                idx = -1;
                for (int i = l + 1; i <= r; i++) {
                    if (nums[i] >= maxi) {
                        maxi = nums[i];
                        idx = i;
                    }
                }
            }
            l++;
            ans[l] = maxi;
        }
        return ans;
    }
};