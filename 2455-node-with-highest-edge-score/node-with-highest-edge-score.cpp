class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> edgeScores(n);
        for (int i = 0; i < n; i++) {
            edgeScores[edges[i]] += i;
        }
        long long winner = 0, maxm = edgeScores[0];
        for (int i = 1; i < n; i++) {
            if (maxm < edgeScores[i]) {
                winner = i;
                maxm = edgeScores[i];
            }
        }
        return winner;
    }
};