class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        // window length from 3 to n
        for (int len = 3; len <= n; ++len) {

            vector<int> freq(26, 0);
            // initialize first window
            for (int i = 0; i < len; i++) {
                freq[s[i] - 'a']++;
            }

            ans += beauty(freq);

            // slide window
            for (int i = len; i < n; i++) {
                freq[s[i] - 'a']++;               // add new char
                freq[s[i - len] - 'a']--;         // remove old char
                ans += beauty(freq);
            }
        }
        return ans;
    }

    // helper to compute max freq - min nonzero freq
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
};
