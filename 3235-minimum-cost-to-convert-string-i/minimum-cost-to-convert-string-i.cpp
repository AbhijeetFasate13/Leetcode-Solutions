class Solution {
    const int INF = 1e9;
    void floydWarshall(vector<vector<int>>& adj) {
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (adj[i][k] < INF && adj[k][j] < INF) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> adj(26, vector<int>(26, INF));
        for (int i = 0; i < 26; i++) {
            adj[i][i] = 0;
        }

        int n = original.size();
        for (int i = 0; i < n; i++) {
            int originalIdx = original[i] - 'a';
            int changedIdx = changed[i] - 'a';
            adj[originalIdx][changedIdx] =
                min(adj[originalIdx][changedIdx], cost[i]);
        }
        floydWarshall(adj);
        long long minCost = 0;
        int len = source.size();
        for (int i = 0; i < len; i++) {
            int a = source[i] - 'a', b = target[i] - 'a';
            if (a == b)
                continue;
            int currCost = adj[a][b];
            if (currCost == INF)
                return -1;
            minCost += currCost;
        }
        return minCost;
    }
};