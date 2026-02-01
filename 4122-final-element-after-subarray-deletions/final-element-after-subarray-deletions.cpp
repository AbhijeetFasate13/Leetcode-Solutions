class Solution {
public:
    int finalElement(vector<int>& nums) {
        return nums[0] < nums.back() ? nums.back() : nums[0];
    }
};