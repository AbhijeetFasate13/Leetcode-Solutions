class Solution {
    pair<int, int> getMinMaxIdx(vector<int>& nums) {
        int minm = nums[0], minIdx = 0;
        int maxm = nums[0], maxIdx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (minm > nums[i]) {
                minm = nums[i];
                minIdx = i;
            }
            if (maxm < nums[i]) {
                maxm = nums[i];
                maxIdx = i;
            }
        }
        // 1-based indexing
        return {minIdx + 1, maxIdx + 1};
    }

public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 1;
        if (n == 2)
            return nums[0] == nums[1] ? 1 : 2;

        auto [a, b] = getMinMaxIdx(nums);
        if (a > b)
            swap(a, b);
        return min({b, n - a + 1, a + n - b + 1});
    }
};