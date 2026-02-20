class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[ptr++] = nums[i];
            }
        }
        return ptr;
    }
};