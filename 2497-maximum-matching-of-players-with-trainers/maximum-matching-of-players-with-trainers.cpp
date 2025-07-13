class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int l = 0, r = 0, m = players.size(), n = trainers.size();
        int count = 0;
        while (l < m and r < n) {
            if (players[l] <= trainers[r]) {
                l++;
                r++;
                count++;
            } else {
                r++;
            }
        }
        return count;
    }
};