class Solution {
    void dfs(int node, vector<bool>& visited,
             const vector<vector<int>>& isConnected) {
        visited[node] = true;
        for (int i = 0; i < isConnected[node].size(); i++) {
            if (!visited[i] and isConnected[node][i]) {
                dfs(i, visited, isConnected);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, isConnected);
                count++;
            }
        }
        return count;
    }
};