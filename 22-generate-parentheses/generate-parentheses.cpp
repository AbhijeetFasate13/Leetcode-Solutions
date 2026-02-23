class Solution {
    void backtrack(const int& n, int& open, int& close, string& curr,
                   vector<string>& ans) {
        if (curr.size() == 2 * n) {
            if (open == close) {
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        open++;
        backtrack(n, open, close, curr, ans);
        open--;
        curr.pop_back();
        if (close < open) {
            curr.push_back(')');
            close++;
            backtrack(n, open, close, curr, ans);
            close--;
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> ans;
        int open = 0, close = 0;
        backtrack(n, open, close, curr, ans);
        return ans;
    }
};