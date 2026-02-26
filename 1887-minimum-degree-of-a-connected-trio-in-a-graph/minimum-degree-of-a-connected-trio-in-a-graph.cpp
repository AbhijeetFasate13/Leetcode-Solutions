class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> degree(n + 1);
        vector<vector<bool>> isConnected(n + 1, vector<bool>(n + 1, false));

        for (const auto& edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            isConnected[edge[0]][edge[1]] = true;
            isConnected[edge[1]][edge[0]] = true;
        }

        int minDegree = INT_MAX;
        for (int i = 1; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                if (!isConnected[i][j])
                    continue;
                for (int k = j + 1; k <= n; k++) {
                    if (!isConnected[i][k] or !isConnected[j][k])
                        continue;
                    minDegree =
                        min(minDegree, degree[i] + degree[j] + degree[k] - 6);
                }
            }
        }
        return minDegree == INT_MAX ? -1 : minDegree;
    }
};