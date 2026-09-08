class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for (int i = 0; i <= n; i++)
            ans += (to_string(i).length() - 1) / 3;
        return ans;
    }
};