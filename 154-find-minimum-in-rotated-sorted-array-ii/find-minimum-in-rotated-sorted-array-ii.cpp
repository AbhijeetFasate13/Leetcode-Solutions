class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = (int)nums.size() - 1;
        int ans = INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[l] == nums[mid] and nums[mid] == nums[r]) {
                ans = min(ans, nums[mid]);
                l++;
                r--;
                continue;
            }
            if (nums[l] <= nums[mid]) {
                ans = min(ans, nums[l]);
                l = mid + 1;
            } else {
                ans = min(ans, nums[mid]);
                r = mid - 1;
            }
        }
        return ans;
    }
};