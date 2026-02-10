class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n - 1; i++) {
            unordered_map<int, int> even, odd;
            if (nums[i] & 1)
                odd[nums[i]]++;
            else
                even[nums[i]]++;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] & 1)
                    odd[nums[j]]++;
                else
                    even[nums[j]]++;
                if (odd.size() == even.size())
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};