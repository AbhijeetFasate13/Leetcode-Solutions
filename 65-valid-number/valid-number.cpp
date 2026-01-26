class Solution {
    bool isDigit(const char& c) { return c >= '0' and c <= '9'; }
    bool isLowerCaseAlpha(const char& c) { return c >= 'a' and c <= 'z'; }
    bool isUpperCaseAlpha(const char& c) { return c >= 'A' and c <= 'Z'; }
    bool isExpo(const char& c) { return c == 'e' or c == 'E'; }
    bool isSign(const char& c) { return c == '-' or c == '+'; }

    bool isInteger(const string& s) {
        if (s.empty())
            return false;
        int n = s.size();
        bool digitEncountered = false;
        for (int i = 0; i < n; i++) {
            if (isSign(s[i]) and i != 0)
                return false;
            if (s[i] == '.')
                return false;
            if (isDigit(s[i]))
                digitEncountered = true;
        }
        return digitEncountered;
        ;
    }
    bool isDecimal(const string& s) {
        int n = s.size();
        if (n <= 1)
            return false;
        bool dotFound = false;
        int start = isSign(s[0]) ? 1 : 0;
        bool digitEncountered = false;
        for (int i = start; i < n; i++) {
            if (isDigit(s[i]))
                digitEncountered = true;
            if (isSign(s[i]) and i != 0)
                return false;

            if (s[i] == '.') {
                if (dotFound)
                    return false;

                if ((i == start || !isDigit(s[i - 1])) &&
                    (i + 1 >= n || !isDigit(s[i + 1])))
                    return false;

                dotFound = true;
            }
        }
        return digitEncountered;
    }
    int getExpoIdx(const string& s) {
        int n = s.size();
        int expoIdx = -1;
        int expoCount = 0;
        int signCount = 0;

        for (int i = 0; i < n; i++) {
            if (isExpo(s[i])) {
                expoCount++;
                expoIdx = i;
                signCount = 0;
                if (i == 0 || i == n - 1)
                    return INT_MIN;
                if (!isDigit(s[i - 1]) and s[i - 1] != '.')
                    return INT_MIN;

                if (!isDigit(s[i + 1]) && !isSign(s[i + 1]))
                    return INT_MIN;

                if (isSign(s[i + 1])) {
                    if (i + 2 >= n || !isDigit(s[i + 2]))
                        return INT_MIN;
                }
            } else if (isSign(s[i])) {
                signCount++;
                if (signCount > 1)
                    return INT_MIN;
            } else if (isLowerCaseAlpha(s[i]) || isUpperCaseAlpha(s[i])) {
                return INT_MIN;
            }
        }

        if (expoCount > 1)
            return INT_MIN;

        return expoIdx;
    }

public:
    bool isNumber(string s) {
        int n = s.size();
        int expoIdx = getExpoIdx(s);
        cout << expoIdx << " ";
        if (expoIdx == INT_MIN)
            return false;
        if (expoIdx == -1)
            return isInteger(s) or isDecimal(s);

        string numBeforeExpo = s.substr(0, expoIdx);

        return (isInteger(numBeforeExpo) or isDecimal(numBeforeExpo)) and
               isInteger(s.substr(expoIdx + 1));
    }
};