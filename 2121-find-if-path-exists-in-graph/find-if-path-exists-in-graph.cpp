class Solution {
    bool isPath(int src, int des, vector<int> adj[], vector<int>& vis) {
        if (src == des)
            return true;
        vis[src] = 1;
        for (auto& i : adj[src]) {
            if (!vis[i] and isPath(i, des, adj, vis)) {
                return true;
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<int> adj[n + 1];
        for (auto& i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n + 1);
        return isPath(source, destination, adj, vis);
    }
};