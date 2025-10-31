class Solution {
    void rec(int i, int n, string &s, vector<string> &result) {
        if (i == n) {
            result.push_back(s);
            return;
        }

        s.push_back('1');
        rec(i + 1, n, s, result);
        s.pop_back();

        if (i == 0 || s.back() == '1') {
            s.push_back('0');
            rec(i + 1, n, s, result);
            s.pop_back();
        }
    }

public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string current;
        rec(0, n, current, result);
        return result;
    }
};
