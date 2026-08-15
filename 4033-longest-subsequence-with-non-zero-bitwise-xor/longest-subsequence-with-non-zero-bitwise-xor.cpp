class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorSum = 0;
        bool atLeastOneNonZero = false;
        for (const int& num : nums) {
            xorSum ^= num;
            if(num){
                atLeastOneNonZero = true;
            }
        }
        if (xorSum != 0)
            return n;
        return atLeastOneNonZero?n - 1:0;
    }
};