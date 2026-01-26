class Solution {
    bool isDigit(char c) { return c >= '0' && c <= '9'; }
    bool isExpo(char c) { return c == 'e' || c == 'E'; }
    bool isSign(char c) { return c == '+' || c == '-'; }

    bool isInteger(const string& s) {
        if (s.empty())
            return false;

        bool digitFound = false;
        for (int i = 0; i < s.size(); i++) {
            if (isSign(s[i]) && i != 0)
                return false;
            if (!isDigit(s[i]) && !isSign(s[i]))
                return false;
            if (isDigit(s[i]))
                digitFound = true;
        }
        return digitFound;
    }

    bool isDecimal(const string& s) {
        if (s.size() <= 1)
            return false;

        int start = isSign(s[0]) ? 1 : 0;
        bool digitFound = false, dotFound = false;

        for (int i = start; i < s.size(); i++) {
            if (isDigit(s[i])) {
                digitFound = true;
            } else if (s[i] == '.') {
                if (dotFound)
                    return false;

                if ((i == start || !isDigit(s[i - 1])) &&
                    (i + 1 >= s.size() || !isDigit(s[i + 1])))
                    return false;

                dotFound = true;
            } else {
                return false;
            }
        }
        return digitFound;
    }

    int getExpoIdx(const string& s) {
        int expoIdx = -1, expoCount = 0, signCount = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isExpo(s[i])) {
                expoIdx = i;
                expoCount++;
                signCount = 0;

                if (i == 0 || i == s.size() - 1)
                    return INT_MIN;
                if (!isDigit(s[i - 1]) && s[i - 1] != '.')
                    return INT_MIN;
                if (!isDigit(s[i + 1]) && !isSign(s[i + 1]))
                    return INT_MIN;

                if (isSign(s[i + 1]) &&
                    (i + 2 >= s.size() || !isDigit(s[i + 2])))
                    return INT_MIN;
            } else if (isSign(s[i])) {
                if (++signCount > 1)
                    return INT_MIN;
            } else if (!isDigit(s[i]) && s[i] != '.') {
                return INT_MIN;
            }
        }
        return expoCount > 1 ? INT_MIN : expoIdx;
    }

public:
    bool isNumber(string s) {
        int expoIdx = getExpoIdx(s);
        if (expoIdx == INT_MIN)
            return false;

        if (expoIdx == -1)
            return isInteger(s) || isDecimal(s);

        return (isInteger(s.substr(0, expoIdx)) ||
                isDecimal(s.substr(0, expoIdx))) &&
               isInteger(s.substr(expoIdx + 1));
    }
};
