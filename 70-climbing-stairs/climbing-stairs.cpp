class Solution {
public:
    int climbStairs(int n) {
        if (n == 2) {
            return 2;
        }
        if (n <= 1) {
            return 1;
        }
        int a = 1, b = 1, c = 2;
        int d;
        for (int i = 3; i <= n; i++) {
            d = b + c;
            b = c;
            c = d;
        }
        return d;
    }
};