class Solution {
    struct Cell {
            int val, i, j;
        };
        const int INF = 1e9;
        vector<Cell> cells;
public:
    int minCost(vector<vector<int>>& grid, int K) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }
        sort(cells.begin(), cells.end(),
             [](const Cell& a, const Cell& b) {
                 return a.val < b.val;
             });
        vector<vector<int>> dpPrev(m, vector<int>(n, INF));
        vector<vector<int>> dpCurr(m, vector<int>(n, INF));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    dpPrev[i][j] = 0;
                } else {
                    int best = INF;
                    if (i + 1 < m)
                        best = min(best, grid[i + 1][j] + dpPrev[i + 1][j]);
                    if (j + 1 < n)
                        best = min(best, grid[i][j + 1] + dpPrev[i][j + 1]);
                    dpPrev[i][j] = best;
                }
            }
        }
        for (int k = 1; k <= K; k++) {
            unordered_map<int, int> best;
            int running_min = INF;
            for (auto &c : cells) {
                running_min = min(running_min, dpPrev[c.i][c.j]);
                best[c.val] = running_min;
            }

            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        dpCurr[i][j] = 0;
                        continue;
                    }

                    int ans = INF;
                    if (j + 1 < n)
                        ans = min(ans, grid[i][j + 1] + dpCurr[i][j + 1]);
                    if (i + 1 < m)
                        ans = min(ans, grid[i + 1][j] + dpCurr[i + 1][j]);
                    ans = min(ans, best[grid[i][j]]);
                    dpCurr[i][j] = ans;
                }
            }
            dpPrev.swap(dpCurr);
        }
        return dpPrev[0][0];
    }
};
