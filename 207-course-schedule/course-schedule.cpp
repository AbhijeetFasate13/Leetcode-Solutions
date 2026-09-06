class Solution {
    vector<int> state;

    bool dfs(int v, vector<vector<int>>& adj) {
        if (state[v] == 1)
            return false;

        if (state[v] == 2)
            return true;

        state[v] = 1;

        for (int neighbor : adj[v]) {
            if (!dfs(neighbor, adj))
                return false;
        }

        state[v] = 2;

        return true;
    }

    vector<vector<int>> buildAdjGraph(const int& n,
                                      vector<vector<int>>& edgeList) {
        vector<vector<int>> adj(n);

        for (const auto& edge : edgeList) {
            adj[edge[1]].push_back(edge[0]);
        }

        return adj;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        state.assign(numCourses, 0);

        vector<vector<int>> adj = buildAdjGraph(numCourses, prerequisites);

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, adj))
                return false;
        }

        return true;
    }
};
