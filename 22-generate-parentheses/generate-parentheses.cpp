class Solution {
    void rec(int open, int close, string curr, vector<string>& allSets) {
        if (open == 0 and close == 0) {
            allSets.push_back(curr);
            return;
        }
        if (open > 0)
            rec(open - 1, close, curr + "(", allSets);
        if (close > open) {
            rec(open, close - 1, curr + ")", allSets);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> allSets;
        rec(n, n, "", allSets);
        return allSets;
    }
};