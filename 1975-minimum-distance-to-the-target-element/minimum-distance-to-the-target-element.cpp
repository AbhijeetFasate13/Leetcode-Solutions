class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minm = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                minm = min(minm, abs(i - start));
            }
        }
        return minm;
    }
};