class Solution {
    int getAns(int num) {
        int i = 0;
        while (num & (1 << i)) {
            num ^= (1 << i);
            i++;
        }
        if (i == 0)
            return num;
        return num | (1 << (i - 1));
    }

public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                ans[i] = -1;
            } else {
                ans[i] = getAns(nums[i]) - 1;
            }
        }
        return ans;
    }
};