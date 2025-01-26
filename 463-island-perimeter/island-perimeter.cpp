class Solution {
    int check(const int& x, const int& y, const int& m, const int& n,
              const vector<vector<int>>& grid) {
        if (x < 0 or x >= n)
            return 1;
        if (y < 0 or y >= m)
            return 1;
        if (grid[x][y] == 0)
            return 1;
        return 0;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = (int)grid.size(), m = (int)grid[0].size();
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int newX, newY;
        int perimeter = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;
                for (int k = 0; k < 4; k++) {
                    newX = dir[k].first, newY = dir[k].second;
                    perimeter += check(i + newX, j + newY, m, n, grid);
                }
            }
        }
        return perimeter;
    }
};