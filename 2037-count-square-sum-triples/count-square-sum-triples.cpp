class Solution {
    bool isSquare(int n) {
        int l = 0, r = n + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (mid * mid <= n) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l * l == n;
    }

public:
    int countTriples(int n) {
        int count = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                int sumOfSquares = (i * i) + (j * j);
                if (sumOfSquares > n * n)
                    break;
                if (isSquare(sumOfSquares)) {
                    count++;
                }
            }
        }
        return count;
    }
};