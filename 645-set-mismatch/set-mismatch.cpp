class Solution {
    void cyclicSort(vector<int>& nums, int n) {
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1 and nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
    }

public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        cyclicSort(nums, n);
        vector<int> errorNums(2);
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                errorNums[0] = nums[i];
                errorNums[1] = i + 1;
            }
        }
        return errorNums;
    }
};