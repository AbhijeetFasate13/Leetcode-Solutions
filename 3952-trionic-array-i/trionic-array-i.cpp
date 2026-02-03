class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = -1, q = -1;
        int n = nums.size();
        for (int i = 1; i < n - 2; i++) {
            if (nums[i] > nums[i - 1]) {
                p = i;
            } else {
                break;
            }
        }
        if (p == -1)
            return false;
        for (int i = p + 1; i < n - 1; i++) {
            if (nums[i] < nums[i - 1]) {
                q = i;
            } else {
                break;
            }
        }
        if (q == -1)
            return false;
        for (int i = q + 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
};