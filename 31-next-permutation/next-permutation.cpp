class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
        1 2 3 4
        1 2 4 3
        1 3 2 4
        1 3 4 2
        1 4 2 3
        1 4 3 2
        2 1 3 4
        2 1 4 3
        2 3 1 4
        2 3 4 1
        2 4 1 3
        2 4 3 1
        3 1 2 4
        */
        int n = nums.size();
        int ind = -1;
        for (int i = n - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                int min = nums[i], minIdx = i;
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] > nums[i - 1] and min >= nums[j]) {
                        min = nums[j];
                        minIdx = j;
                    }
                }
                swap(nums[i - 1], nums[minIdx]);
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            reverse(begin(nums), end(nums));
        } else {
            reverse(nums.begin() + ind, nums.end());
        }
    }
};