class Solution {
public:
    int totalMoney(int n) {
        if (n < 7) {
            return n * (n + 1) / 2;
        }
        int groups = n / 7;
        int sum = 28 * groups + 7 * (groups * (groups - 1)) / 2;
        if (n % 7 != 0) {
            for (int i = groups + 1; i < groups + 1 + n % 7; i++) {
                sum += i;
            }
        }
        return sum;
    }
};