class Solution {
    vector<vector<int>> buildAdjMat(const int& n,
                                    const vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>(n));
        for (const auto& edge : edges) {
            adj[edge[0]][edge[1]] = 1;
        }
        return adj;
    }

public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj = buildAdjMat(n, edges);
        vector<int> loser(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == 1) {
                    loser[j]++;
                }
            }
        }
        int winner = -1;
        for (int i = 0; i < n; i++) {
            if (loser[i] == 0) {
                if (winner != -1) {
                    return -1;
                }
                winner = i;
            }
        }
        return winner;
    }
};