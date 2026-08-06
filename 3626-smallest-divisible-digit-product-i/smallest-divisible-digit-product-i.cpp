class Solution {
    int digitProd(int n) {
        int res = 1;
        while (n) {
            res *= n % 10;
            n /= 10;
        }
        return res;
    }

public:
    int smallestNumber(int n, int t) {
        while (digitProd(n) % t) {
            n++;
        }
        return n;
    }
};