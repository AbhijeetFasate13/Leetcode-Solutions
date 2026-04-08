class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int start, end, jump, mult;
        const int m = 1e9 + 7;
        long long temp;
        for (const auto& q : queries) {
            start = q[0], end = q[1], jump = q[2], mult = q[3];
            for (int i = start; i <= end; i += jump) {
                temp = nums[i];
                temp = (temp * mult) % m;
                nums[i] = temp;
            }
        }
        int ans = 0;
        for (const int& i : nums) {
            ans ^= i;
        }
        return ans;
    }
};