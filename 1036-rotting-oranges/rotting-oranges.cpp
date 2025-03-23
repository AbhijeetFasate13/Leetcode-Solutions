class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshOranges = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!grid[i][j])
                    continue;
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else {
                    freshOranges++;
                }
            }
        }
        int rot = 0, time = 0;
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!q.empty()) {
            if(rot==freshOranges)break;
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int xn = x + dir[d][0], yn = y + dir[d][1];
                    if (xn < 0 or yn < 0 or xn == grid.size() or
                        yn == grid[0].size() or grid[xn][yn] == 0 or
                        grid[xn][yn] == 2)
                        continue;
                    grid[xn][yn] = 2;
                    rot++;
                    q.push({xn, yn});
                }
            }
            time++;
        }
        if (rot != freshOranges)
            return -1;
        return time;
    }
};