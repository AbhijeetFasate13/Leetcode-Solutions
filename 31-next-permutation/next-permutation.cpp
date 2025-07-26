class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int l = n - 2;
        while (l >= 0 && nums[l] >= nums[l + 1]) {
            l--;
        }

        if (l >= 0) {
            int r = n - 1;
            while (nums[r] <= nums[l]) {
                r--;
            }
            swap(nums[l], nums[r]);
        }
        reverse(nums.begin() + l + 1, nums.end());
    }
};
