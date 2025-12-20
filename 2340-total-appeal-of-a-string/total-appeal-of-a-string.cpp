class Solution {
    long long contributionOf(char c, const string& s) {
        int n = s.size();
        long long totalSubstrings = n * (n + 1ll) / 2;
        int len = 0;
        for (const char& i : s) {
            if (i != c) {
                len++;
            } else {
                totalSubstrings -= len * (len + 1ll) / 2;
                len = 0;
            }
        }
        return totalSubstrings - len * (len + 1ll) / 2;
    }

public:
    long long appealSum(string s) {
        long long appeal = 0;
        for (int i = 0; i < 26; i++) {
            appeal += contributionOf((char)(i + 'a'), s);
        }
        return appeal;
    }
};