class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(begin(sortedNums), end(sortedNums));
        int ans = -1, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != sortedNums[i]) {
                if (ans == -1)
                    ans = nums[i];
                else
                    ans &= nums[i];
            }
        }
        return ans==-1 ? 0:ans;
    }
};