class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefix(n + 1);
        prefix[1] = 1 << (s[0] - 'a');
        for (int i = 2; i <= n; i++) {
            prefix[i] = prefix[i - 1] ^ (1 << (s[i - 1] - 'a'));
        }

        int left, right, k, mask;
        vector<bool> ans;
        for (const vector<int>& query : queries) {
            left = query[0], right = query[1], k = query[2];
            int mask = prefix[right + 1] ^ prefix[left];
            if (__builtin_popcount(mask) / 2 <= k) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};