class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int r = entrance[0], c = entrance[1];
        queue<pair<int,int>> q;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        q.push({r, c});
        dist[r][c] = 0;
        while (!q.empty()) {
            auto [nR, nC] = q.front();
            q.pop();
            for (auto &d : dir) {
                int newR = nR + d[0];
                int newC = nC + d[1];
                if (newR < 0 || newR >= m || newC < 0 || newC >= n) continue;
                if (maze[newR][newC] == '+') continue;
                if (dist[newR][newC] != -1) continue;
                dist[newR][newC] = dist[nR][nC] + 1;
                if (newR == 0 || newR == m - 1 || newC == 0 || newC == n - 1) {
                    return dist[newR][newC];
                }

                q.push({newR, newC});
            }
        }

        return -1;
    }
};
