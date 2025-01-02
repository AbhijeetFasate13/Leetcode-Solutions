class Solution {
    bool isVowel(char s) {
        return s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u';
    }

public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = (int)words.size();
        vector<int> count(n + 1);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                count[i + 1] =
                    (isVowel(words[i][0]) and isVowel(words[i].back()) ? 1 : 0);
            } else {
                count[i + 1] =
                    count[i] +
                    (isVowel(words[i][0]) and isVowel(words[i].back()) ? 1 : 0);
            }
        }

        int m = (int)queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = count[queries[i][1] + 1] - count[queries[i][0]];
        }
        return ans;
    }
};