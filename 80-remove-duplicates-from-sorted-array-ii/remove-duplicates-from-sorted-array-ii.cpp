class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i <= 1 or nums[ptr - 2] != nums[i]) {
                nums[ptr++] = nums[i];
            }
        }
        return ptr;
    }
};