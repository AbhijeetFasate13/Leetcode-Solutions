class Solution {
    vector<vector<int>> dp;
    int rec(int i, int m, vector<int>& piles) {
        if (i == piles.size())
            return 0;
        if (dp[i][m] != -1)
            return dp[i][m];
        int ans = INT_MIN;
        int sum = 0;
        for (int x = 1; x <= min(2 * m, (int)piles.size() - i); x++) {
            sum += piles[i + x - 1];
            ans = max(ans,
                      sum - rec(i + x, max(m, x), piles));
        }
        return dp[i][m] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n + 1, -1));
        int diff = rec(0, 1, piles);
        int total = accumulate(piles.begin(), piles.end(), 0);
        return (total + diff) / 2;
    }
};