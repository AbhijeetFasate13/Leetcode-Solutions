class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0;
        int maxLen = len;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                len++;
            } else {
                maxLen = max(len, maxLen);
                len = 0;
            }
        }
        return max(len, maxLen);;
    }
};