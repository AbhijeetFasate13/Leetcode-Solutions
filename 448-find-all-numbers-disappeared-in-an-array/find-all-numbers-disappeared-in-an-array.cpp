class Solution {
    void cyclicSort(vector<int>& nums, int n) {
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1 and nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
    }

public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        cyclicSort(nums, n);
        vector<int> missing;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                missing.push_back(i + 1);
            }
        }
        return missing;
    }
};