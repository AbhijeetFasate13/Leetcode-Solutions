class Solution {
    void rec(int i, int open, const string& s, string& curr,
             unordered_set<string>& ans) {
        if (i == s.size()) {
            if (open == 0)
                ans.insert(curr);
            return;
        }

        if (s[i] >= 'a' && s[i] <= 'z') {
            curr.push_back(s[i]);
            rec(i + 1, open, s, curr, ans);
            curr.pop_back();
            return;
        }

        int prevOpen = open;
        if (s[i] == '(')
            open++;
        else
            open--;

        if (open >= 0) {
            curr.push_back(s[i]);
            rec(i + 1, open, s, curr, ans);
            curr.pop_back();
        }
        open = prevOpen;
        rec(i + 1, open, s, curr, ans);
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        string curr;
        unordered_set<string> ans;

        rec(0, 0, s, curr, ans);

        int maxSize = 0;

        for (const string& str : ans)
            maxSize = max(maxSize, (int)str.length());

        vector<string> finalAns;

        for (const string& str : ans) {
            if ((int)str.length() == maxSize)
                finalAns.push_back(str);
        }

        return finalAns;
    }
};