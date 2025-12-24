class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int r = entrance[0], c = entrance[1];
        queue<pair<int, int>> q;
        vector<vector<int>> shortestPath(m, vector<int>(n, INT_MAX));
        shortestPath[r][c] = 0;
        q.push({r, c});
        while (!q.empty()) {
            auto [nR, nC] = q.front();
            q.pop();
            // top
            if (nR != 0 and maze[nR - 1][nC] != '+' and
                shortestPath[nR - 1][nC] == INT_MAX) {
                q.push({nR - 1, nC});
                shortestPath[nR - 1][nC] = 1 + shortestPath[nR][nC];
            }
            // bottom
            if (nR != m - 1 and maze[nR + 1][nC] != '+' and
                shortestPath[nR + 1][nC] == INT_MAX) {
                q.push({nR + 1, nC});
                shortestPath[nR + 1][nC] = 1 + shortestPath[nR][nC];
            }
            // left
            if (nC != 0 and maze[nR][nC - 1] != '+' and
                shortestPath[nR][nC - 1] == INT_MAX) {
                q.push({nR, nC - 1});
                shortestPath[nR][nC - 1] = 1 + shortestPath[nR][nC];
            }
            // right
            if (nC != n - 1 and maze[nR][nC + 1] != '+' and
                shortestPath[nR][nC + 1] == INT_MAX) {
                q.push({nR, nC + 1});
                shortestPath[nR][nC + 1] = 1 + shortestPath[nR][nC];
            }
        }
        int ans = INT_MAX;
        // top row
        for (int i = 0; i < n; i++) {
            if (r == 0 and c == i)
                continue;
            ans = min(ans, shortestPath[0][i]);
        }
        // bottom row
        for (int i = 0; i < n; i++) {
            if (r == m - 1 and c == i)
                continue;
            ans = min(ans, shortestPath[m - 1][i]);
        }
        // leftmost col
        for (int i = 0; i < m; i++) {
            if (r == i and c == 0)
                continue;
            ans = min(ans, shortestPath[i][0]);
        }
        // rightmost col
        for (int i = 0; i < m; i++) {
            if (r == i and c == n - 1)
                continue;
            ans = min(ans, shortestPath[i][n - 1]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};