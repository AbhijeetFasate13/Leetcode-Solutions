class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> loser(n);
        int winner = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    loser[j]++;
                    if (loser[i] == 0) {
                        winner = i;
                    }
                }
            }
        }
        return winner;
    }
};