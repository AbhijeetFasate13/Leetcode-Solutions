class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0;
        int sum = 0, maxSum = 0;
        unordered_map<int, int> mp;
        for (int r = 0; r < nums.size(); r++) {
            int a = nums[r];
            mp[a]++;
            sum += a;
            while (mp[a] > 1) {
                int b = nums[l++];
                mp[b]--;
                sum -= b;
            }
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};