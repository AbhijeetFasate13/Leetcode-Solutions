class Solution {
    void helper(int& sum, int xo, int i, vector<int>& nums) {
        if (i == nums.size()) {
            sum += xo;
            return;
        }
        helper(sum, xo, i + 1, nums);
        helper(sum, xo ^ nums[i], i + 1, nums);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        helper(sum, 0, 0, nums);
        return sum;
    }
};