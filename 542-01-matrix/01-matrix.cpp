class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = (int)mat.size(), n = (int)mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mat[i][j]) {
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                }
            }
        }
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            for (const auto& i : dir) {
                int xn = x + i[0];
                int yn = y + i[1];
                if (xn >= 0 and xn < m and yn >= 0 and yn < n and
                    ans[xn][yn] == -1) {
                    ans[xn][yn] = dis + 1;
                    q.push({{xn, yn}, ans[xn][yn]});
                }
            }
        }
        return ans;
    }
};