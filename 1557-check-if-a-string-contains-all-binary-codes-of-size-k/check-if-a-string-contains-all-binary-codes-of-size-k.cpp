class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> unique;
        int n = s.size();
        for (int i = 0; i < n - k + 1; i++) {
            unique.insert(s.substr(i, k));
        }
        int reqd = 1 << k;
        return unique.size() == reqd;
    }
};