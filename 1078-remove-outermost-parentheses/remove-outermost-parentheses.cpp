class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n = s.size();
        string ans;
        int openCount = 0, closeCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                openCount++;
            } else {
                st.push(s[i]);
                closeCount++;
                if (openCount == closeCount) {
                    st.pop();
                    string temp;
                    while (st.size() > 1) {
                        temp.push_back(st.top());
                        st.pop();
                    }
                    st.pop();
                    openCount = closeCount = 0;
                    reverse(begin(temp), end(temp));
                    ans += temp;
                }
            }
        }
        return ans;
    }
};