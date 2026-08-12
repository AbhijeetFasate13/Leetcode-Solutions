class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0, right = 0, maxLen = 0;
        unordered_map<int, int> hash;
        int n = (int)nums.size();
        while (right < n) {
            hash[nums[right]]++;
            while (hash[nums[right]] > k) {
                hash[nums[left++]]--;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};