class Solution {
    int hammingDist(const string& a, const string& b) {
        int dist = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                dist++;
        }
        return dist;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> parent(n);
        iota(begin(parent), end(parent), 0);
        int ind = 0;
        int max = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[j] != groups[i] and
                    words[j].size() == words[i].size() and
                    hammingDist(words[i], words[j]) == 1 and
                    dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    parent[i] = j;
                }
            }
            if (max < dp[i]) {
                max = dp[i];
                ind = i;
            }
        }
        vector<string> ans;
        while (parent[ind] != ind) {
            ans.push_back(words[ind]);
            ind = parent[ind];
        }
        ans.push_back(words[ind]);
        reverse(begin(ans), end(ans));
        return ans;
    }
};