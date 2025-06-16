class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int smallEl = nums[0], n = (int)nums.size();
        int largeEl = -1;
        int maxDiff = largeEl - smallEl;
        for (int i = 1; i < n; i++) {
            if (nums[i] < smallEl) {
                smallEl = nums[i];
                largeEl = -1;
            } else if (nums[i] > largeEl) {
                largeEl = nums[i];
            }
            maxDiff = max(maxDiff, largeEl - smallEl);
        }
        if (maxDiff <= 0)
            return -1;
        return maxDiff;
    }
};