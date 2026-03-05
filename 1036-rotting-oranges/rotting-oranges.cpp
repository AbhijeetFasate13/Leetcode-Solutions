class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshOranges = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        int time = 0;
        vector<int> dirX = {-1, 0, 1, 0};
        vector<int> dirY = {0, -1, 0, 1};
        while (!q.empty()) {
            if (!freshOranges)
                break;
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int xn = x + dirX[d], yn = y + dirY[d];
                    if (xn < 0 or yn < 0 or xn == grid.size() or
                        yn == grid[0].size() or grid[xn][yn] == 0 or
                        grid[xn][yn] == 2)
                        continue;
                    grid[xn][yn] = 2;
                    freshOranges--;
                    q.push({xn, yn});
                }
            }
            time++;
        }
        if (freshOranges)
            return -1;
        return time;
    }
};