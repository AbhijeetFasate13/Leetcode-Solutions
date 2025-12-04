class Solution {
    int beauty(const vector<int>& freq) {
        int mx = 0, mn = INT_MAX;
        for (int f : freq) {
            if (f > 0) {
                mx = max(mx, f);
                mn = min(mn, f);
            }
        }
        return mx - mn;
    }

public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int len = 3; len <= n; ++len) {
            vector<int> freq(26, 0);
            for (int i = 0; i < len; i++) {
                freq[s[i] - 'a']++;
            }
            ans += beauty(freq);
            for (int i = len; i < n; i++) {
                freq[s[i] - 'a']++;
                freq[s[i - len] - 'a']--;
                ans += beauty(freq);
            }
        }
        return ans;
    }
};
