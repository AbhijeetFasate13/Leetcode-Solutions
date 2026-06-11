class Solution {
    const int mod = 1000000007;
    int dfs(int node, int parent, vector<vector<int>>& adj) {
        int height = 0;
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                height = max(height, 1 + dfs(neighbor, node, adj));
            }
        }
        return height;
    }

    long long binpow(long long base, int exp) {
        long long res = 1;

        while (exp) {
            if (exp & 1)
                res = res * base % mod;

            base = base * base % mod;
            exp >>= 1;
        }

        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int height = dfs(1, 0, adj);
        return binpow(2, height - 1);
    }
};