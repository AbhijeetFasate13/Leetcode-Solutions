class Solution {
    vector<vector<int>> dp;
    int k;
    int n;
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    int helper(int i, int j, const string& s) {
        if (i + k > n)
            return 0;

        if (j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int take = 0;
        int grow = 0;
        int slide = 0;

        if (isPalindrome(s, i, j)) {
            take = 1 + helper(j + 1, j + k, s);
            grow = helper(i, j + 1, s);
            slide = helper(i + 1, j + 1, s);
            return dp[i][j] = max({take, grow, slide});
        }
        grow = helper(i, j + 1, s);
        slide = helper(i + 1, j + 1, s);
        return dp[i][j] = max(grow, slide);
    }

public:
    int maxPalindromes(string s, int k) {
        this->k = k;
        this->n = s.size();
        if(k==1)return n;
        dp.assign(n, vector<int>(n + k + 1, -1));

        return helper(0, k - 1, s);
    }
};
