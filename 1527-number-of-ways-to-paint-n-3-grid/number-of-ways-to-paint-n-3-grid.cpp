class Solution {
public:
    int numOfWays(int n) {
        const int mod = 1e9 + 7;

        // aba: patterns like RGR, BRB, etc. (first == third)
        // abc: patterns like RGB, RBG, etc. (all different)
        long long aba = 6; // for n = 1
        long long abc = 6; // for n = 1

        for (int i = 2; i <= n; i++) {
            long long new_aba = (aba * 3 + abc * 2) % mod;
            long long new_abc = (aba * 2 + abc * 2) % mod;
            aba = new_aba;
            abc = new_abc;
        }

        return (aba + abc) % mod;
    }
};
