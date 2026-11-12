class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1, incLen = 1, decLen = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                incLen++;
                ans = max({ans, incLen, decLen});
                decLen = 1;
            } else if (nums[i] < nums[i - 1]) {
                decLen++;
                ans = max({ans, incLen, decLen});
                incLen = 1;
            } else {
                decLen = 1;
                incLen = 1;
            }
        }
        ans = max({ans, incLen, decLen});

        return ans;
    }
};