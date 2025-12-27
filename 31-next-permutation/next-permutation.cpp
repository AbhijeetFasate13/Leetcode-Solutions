class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for (int i = n - 1; i >= 1; i--) {
            //find first pair which are ordered (asc)
            if (nums[i] > nums[i - 1]) {
                int min = nums[i], minIdx = i;
                //find the min element just greater than less of ordered pair
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] > nums[i - 1] and min >= nums[j]) {
                        min = nums[j];
                        minIdx = j;
                    }
                }
                //swap that min with lesser of ordered pair
                swap(nums[i - 1], nums[minIdx]);
                ind = i;
                break;
            }
        }
        //reverse from greater of ordered pair to end
        if (ind == -1) {
            reverse(begin(nums), end(nums));
        } else {
            reverse(nums.begin() + ind, nums.end());
        }
    }
};