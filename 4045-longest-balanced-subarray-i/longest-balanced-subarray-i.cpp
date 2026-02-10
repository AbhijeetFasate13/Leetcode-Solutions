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

                int len = j - i + 1;

                if (len > maxLen && even.size() == odd.size())
                    maxLen = len;
            }
        }
        return maxLen;
    }
};