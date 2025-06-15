class Solution {
    string replace(string original, string& transformed, int idx,
                   char replaceChar) {
        for (int i = 0; i < (int)original.size(); i++) {
            if (original[i] == original[idx]) {
                transformed[i] = replaceChar;
            }
        }
        return transformed;
    }
    int firstCharDiffThan(int original, string given, char except) {
        int diff = 0;
        while (given[diff] == given[original] or given[diff] == except) {
            diff++;
        }
        return diff;
    }

public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = (int)s.size();
        string a = s, b = s;
        replace(s, a, 0, '9');
        replace(s, b, 0, '1');
        if (s[0] == '9') {
            int diff = firstCharDiffThan(0, s, '9');
            if (diff != n) {
                replace(s, a, diff, '9');
            }
        } else if (s[0] == '1') {
            int diff = firstCharDiffThan(0, s, '0');
            if (diff != n) {
                replace(s, b, diff, '0');
            }
        }
        return stoi(a) - stoi(b);
    }
};