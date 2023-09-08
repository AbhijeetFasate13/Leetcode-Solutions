bool isPerfectSquare(int x) {
    int root = sqrt(x);
    return root * root == x;
}

int numSquares(int n) {
        // Check if n is a perfect square
        if (isPerfectSquare(n)) {
            return 1;
        }

        // Check if n can be represented as n = 4^k * (8 * m + 7)
        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }

        // Check if n can be represented as a sum of two squares
        for (int a = 1; a * a <= n; a++) {
            int b = n - a * a;
            if (isPerfectSquare(b)) {
                return 2;
            }
        }

        // If no previous conditions met, return 3
        return 3;
}

