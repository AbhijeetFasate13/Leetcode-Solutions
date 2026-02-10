class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int missing = k;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == missing) {
                missing += k;
            }
        }
        return missing;
    }
};