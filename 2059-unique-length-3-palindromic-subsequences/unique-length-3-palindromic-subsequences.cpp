class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        if (n == 3) {
            return s[0] == s[2];
        }
        int l = 0, r = n - 1;
        unordered_set<string> unique;
        vector<int> visited(26);
        for (int l = 0; l < n - 2; l++) {
            if (!visited[s[l] - 'a'])
                for (int r = n - 1; r >= l + 2; r--) {
                    if (s[l] == s[r]) {
                        string pal(3, s[l]);
                        int count = 0;
                        for (int i = l + 1; i < r; i++) {
                            pal[1] = s[i];
                            if (unique.find(pal) == unique.end()) {
                                unique.insert(pal);
                                count++;
                            }
                            if (count == 26) {
                                break;
                            }
                        }
                        visited[s[l] - 'a']++;
                        break;
                    }
                }
        }
        return unique.size();
    }
};