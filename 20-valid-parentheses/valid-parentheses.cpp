class Solution {
    bool isOpening(char c) { return c == '(' or c == '{' or c == '['; }
    bool isOpp(char curr, char prev) {
        return (curr == ')' and prev == '(') or (curr == '}' and prev == '{') or
               (curr == ']' and prev == '[');
    }

public:
    bool isValid(string s) {
        stack<char> st;
        int openCount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isOpening(s[i])) {
                st.push(s[i]);
                openCount++;
            } else if (i != 0 and openCount and isOpp(s[i], st.top())) {
                st.pop();
                openCount--;
            } else {
                return false;
            }
        }
        return st.empty();
    }
};