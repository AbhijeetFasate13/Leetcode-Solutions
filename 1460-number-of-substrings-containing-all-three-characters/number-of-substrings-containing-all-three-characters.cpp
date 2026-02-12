class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int a = -1, b = -1, c = -1;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                a = i;
            else if (s[i] == 'b')
                b = i;
            else
                c = i;
            int minm = min({a, b, c});
            if (minm != -1) {
                ans += minm + 1;
            }
        }
        return ans;
    }
};