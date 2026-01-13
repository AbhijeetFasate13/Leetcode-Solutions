class Solution {
    unordered_map<char, int> mp;

public:
    Solution() {
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
    }
    int romanToInt(string s) {
        int num = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i != n - 1 and s[i] == 'I' and
                (s[i + 1] == 'V' or s[i + 1] == 'X')) {
                num += s[i + 1] == 'X' ? 9 : 4;
                i++;
            } else if (i != n - 1 and s[i] == 'X' and
                       (s[i + 1] == 'L' or s[i + 1] == 'C')) {
                num += s[i + 1] == 'C' ? 90 : 40;
                i++;
            } else if (i != n - 1 and s[i] == 'C' and
                       (s[i + 1] == 'D' or s[i + 1] == 'M')) {
                num += s[i + 1] == 'M' ? 900 : 400;
                i++;
            } else {
                num += mp[s[i]];
            }
        }
        return num;
    }
};