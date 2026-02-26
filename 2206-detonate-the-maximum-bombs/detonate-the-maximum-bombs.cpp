class Solution {
    bool canDetonate(const vector<int>& a, const vector<int>& b) {
        long long dx = a[0] - b[0];
        long long dy = a[1] - b[1];
        long long distSq = dx * dx + dy * dy;
        long long radiusSq = 1LL * a[2] * a[2];
        return distSq <= radiusSq;
    }

    vector<vector<int>> buildAdjacencyList(const vector<vector<int>>& bombs,
                                           int n) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (canDetonate(bombs[i], bombs[j])) {
                    adj[i].push_back(j);
                }
            }
        }
        return adj;
    }

    int dfs(int src, vector<bool>& visited, const vector<vector<int>>& adj) {
        visited[src] = true;
        int count = 1;
        for (int nbr : adj[src]) {
            if (!visited[nbr]) {
                count += dfs(nbr, visited, adj);
            }
        }
        return count;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj = buildAdjacencyList(bombs, n);
        int maxm = 1;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            maxm = max(maxm, dfs(i, visited, adj));
        }

        return maxm;
    }
};