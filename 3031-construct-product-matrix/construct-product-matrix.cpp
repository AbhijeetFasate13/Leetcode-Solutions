class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int m = grid.size(), n = grid[0].size();

        vector<int> arr;
        for (auto &row : grid)
            for (auto &x : row)
                arr.push_back(x % MOD);

        int size = arr.size();
        vector<int> prefix(size, 1), suffix(size, 1);

        for (int i = 1; i < size; i++) {
            prefix[i] = (1LL * prefix[i - 1] * arr[i - 1]) % MOD;
        }

        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (1LL * suffix[i + 1] * arr[i + 1]) % MOD;
        }

        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < size; i++) {
            ans[i / n][i % n] = (1LL * prefix[i] * suffix[i]) % MOD;
        }

        return ans;
    }
};