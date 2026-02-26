class Solution {
    vector<vector<int>> buildAdjList(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }

public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj = buildAdjList(n, edges);
        int maxm = INT_MIN;
        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end(),
                 [&](int a, int b) { return vals[a] > vals[b]; });

            int sum = vals[i];
            for (int j = 0; j < min(k, (int)adj[i].size()); j++) {
                if (vals[adj[i][j]] <= 0)
                    break;
                sum += vals[adj[i][j]];
            }
            maxm = max(maxm, sum);
        }

        return maxm;
    }
};