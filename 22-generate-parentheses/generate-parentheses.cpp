class Solution {
    void backtrack(const int& n, int open, int close, string& curr,
                   vector<string>& ans) {
        if (curr.size() == 2 * n) {
            if (open == close) {
                ans.push_back(curr);
            }
            return;
        }
        if (open < n) {
            curr.push_back('(');
            backtrack(n, open + 1, close, curr, ans);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            backtrack(n, open, close + 1, curr, ans);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> ans;
        backtrack(n, 0, 0, curr, ans);
        return ans;
    }
};