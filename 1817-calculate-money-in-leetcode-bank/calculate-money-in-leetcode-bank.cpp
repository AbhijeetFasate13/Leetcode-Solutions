class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        int totalMoney = 28 * weeks + 7 * (weeks * (weeks - 1) / 2);
        int start = weeks + 1;
        for (int i = 0; i < days; i++) {
            totalMoney += start + i;
        }
        return totalMoney;
    }
};