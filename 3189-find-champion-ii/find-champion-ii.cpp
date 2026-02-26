class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> loser(n);
        for (const auto& edge : edges) {
            loser[edge[1]] = 1;
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