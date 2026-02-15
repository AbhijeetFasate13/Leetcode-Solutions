class Solution {
public:
    int expand(string& s, int& l, int& r, int flag = 0) {
        int n = s.size();
        int res = 0;
        while (l >= 0 && r < n and s[l] == s[r]) {
            res = max(res, r - l + 1 + flag);
            l--;
            r++;
        }
        return res;
    }

    int almostPalindromic(string s) {
        int n = s.size();
        int ans = 1;
        int l, r, sl, sr, temp;
        for (int i = 0; i < n; i++) {
            // odd
            l = r = i;
            ans = max(ans, expand(s, l, r, 1));
            sl = l - 1, sr = r;
            ans = max(ans, expand(s, sl, sr));
            sl = l, sr = r + 1;
            ans = max(ans, expand(s, sl, sr));
            // even
            if (i + 1 < n) {
                l = i, r = i + 1;
                ans = max(ans, expand(s, l, r, 1));
                sl = l - 1, sr = r;
                ans = max(ans, expand(s, sl, sr));
                sl = l, sr = r + 1;
                ans = max(ans, expand(s, sl, sr));
            }
        }

        return min(ans, n);
    }
};
