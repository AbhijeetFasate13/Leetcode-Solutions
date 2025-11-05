class Solution {
    void clearLeadingWhitespaces(string& s) {
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        s = s.substr(i);
        return;
    }

    void clearLeadingZeroes(string& s) {
        int startIdx = 0;
        while (s[startIdx] == '0') {
            startIdx++;
        }
        s = s.substr(startIdx);
        return;
    }

public:
    int myAtoi(string s) {
        clearLeadingWhitespaces(s);
        bool isNeg = false;
        if (s[0] == '-' or s[0] == '+') {
            isNeg = (s[0] == '-');
            s = s.substr(1);
        }
        clearLeadingZeroes(s);
        int num = 0;
        long long intMin = -1ll * INT_MIN;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' and s[i] <= '9') {
                int digit = s[i] - '0';
                // cout<<digit<<" ";
                if (isNeg and num >= (intMin - digit) / 10) {
                    if (num == intMin / 10 and digit < 8) {
                        return -(num * 10 + digit);
                    }
                    return INT_MIN;
                }
                if (!isNeg and num > (INT_MAX - digit) / 10) {
                    return INT_MAX;
                }
                num = num * 10 + digit;
            } else {
                break;
            }
        }
        return isNeg ? -num : num;
    }
};