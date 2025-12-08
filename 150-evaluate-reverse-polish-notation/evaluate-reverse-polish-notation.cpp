class Solution {
    int doMath(int a, int b, string op) {
        if (op == "+") {
            return a + b;
        } else if (op == "-") {
            return b - a;
        } else if (op == "/") {
            return b / a;
        } else {
            return a * b;
        }
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> eval;
        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            try {
                int num = stoi(s);
                eval.push(num);
            } catch (...) {
                int a = eval.top();
                eval.pop();
                int b = eval.top();
                eval.pop();
                eval.push(doMath(a, b, s));
            }
        }
        return eval.top();
    }
};