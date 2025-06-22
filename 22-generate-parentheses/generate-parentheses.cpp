class Solution {
    void rec(int idx, int n, int sum, string curr, vector<string>& allSets) {
        if (idx == 2*n) {
            if (sum == 0) {
                allSets.push_back(curr);
            }
            return;
        }
        rec(idx + 1, n, sum + 1, curr + "(", allSets);
        if (sum != 0) {
            rec(idx + 1, n, sum - 1, curr + ")", allSets);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> allSets;
        rec(0, n, 0, curr, allSets);
        return allSets;
    }
};