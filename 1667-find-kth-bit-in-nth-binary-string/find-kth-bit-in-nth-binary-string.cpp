class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1 and k == 1)
            return '0';
        int total = pow(2, n) - 1;
        if (k <= total / 2) {
            return findKthBit(n - 1, k);
        }
        if (k == (total / 2) + 1)
            return '1';
        return findKthBit(n - 1, total - k + 1) == '1' ? '0' : '1';
    }
};