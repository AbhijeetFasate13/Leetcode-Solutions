class Solution {
    vector<int> state;
    vector<int> ans;

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
        ans.push_back(v);

        return true;
    }

    vector<vector<int>> buildAdjGraph(int n,
                                      vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        return adj;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        state.assign(numCourses, 0);
        ans.clear();

        vector<vector<int>> adj = buildAdjGraph(numCourses, prerequisites);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, adj))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
