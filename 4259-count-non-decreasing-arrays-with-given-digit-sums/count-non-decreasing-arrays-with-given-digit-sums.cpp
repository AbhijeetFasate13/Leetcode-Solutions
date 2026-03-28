class Solution {
    vector<vector<int>> nums;
    vector<vector<int>> dp;
    const int m = 1e9 + 7;
    int sumOfDigits(int i) {
        int sum = 0;
        while (i) {
            sum += i % 10;
            i /= 10;
        }
        return sum;
    }
    int rec(int i, vector<int>& digitSum, int idx) {
        if (idx >= nums[digitSum[i]].size()) {
            return 0;
        }
        if (dp[i][idx] != -1)
            return dp[i][idx];
        if (i == digitSum.size() - 1) {
            return dp[i][idx] = (1 + rec(i, digitSum, idx + 1)) % m;
        }
        int nextSum = digitSum[i + 1], curSum = digitSum[i];
        int nextIdx = lower_bound(nums[nextSum].begin(), nums[nextSum].end(),
                                  nums[curSum][idx]) -
                      nums[nextSum].begin();
        return dp[i][idx] =
                   (rec(i + 1, digitSum, nextIdx) + rec(i, digitSum, idx + 1)) %
                   m;
    }

public:
    Solution() {
        nums.resize(51);
        for (int i = 0; i < 5001; i++) {
            nums[sumOfDigits(i)].push_back(i);
        }
    }
    int countArrays(vector<int>& digitSum) {
        int n = digitSum.size();
        dp.resize(n + 1, vector<int>(5001, -1));
        return rec(0, digitSum, 0);
    }
};