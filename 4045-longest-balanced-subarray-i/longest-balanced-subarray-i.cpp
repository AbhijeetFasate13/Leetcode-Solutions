class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n - maxLen; i++) {
            unordered_map<int, int> even, odd;
            for (int j = i; j < n; j++) {
                if (nums[j] & 1)
                    odd[nums[j]]++;
                else
                    even[nums[j]]++;
                if (j - i + 1 > maxLen && even.size() == odd.size())
                    maxLen = j - i + 1;
            }
        }
        return maxLen;
    }
};