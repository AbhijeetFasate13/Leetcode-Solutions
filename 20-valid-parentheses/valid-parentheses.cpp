class Solution {
    bool isClosing(char& a, const char& b) {
        if (a == '(' and b == ')')
            return true;
        if (a == '[' and b == ']')
            return true;
        if (a == '{' and b == '}')
            return true;
        return false;
    }

public:
    bool isValid(string s) {
        stack<char> st;
        for (const char& c : s) {
            if (c == '(' or c == '[' or c == '{')
                st.push(c);
            else if (st.empty() or !isClosing(st.top(), c)) {
                return false;
            } else {
                st.pop();
            }
        }
        return st.empty();
    }
};