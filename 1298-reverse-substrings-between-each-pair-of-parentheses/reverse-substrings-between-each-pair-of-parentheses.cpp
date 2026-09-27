class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> link(n), stk;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                stk.push_back(i);
            else if (s[i] == ')') {
                link[i] = stk.back();
                link[link[i]] = i;
                stk.pop_back();
            }
        }

        string ans;

        for (int i = 0, dir = 1; i < n; i += dir) {
            if (s[i] >= 'a' and s[i] <= 'z') {
                ans.push_back(s[i]);
            } else {
                i = link[i];
                dir = -dir;
            }
        }

        return ans;
    }
};