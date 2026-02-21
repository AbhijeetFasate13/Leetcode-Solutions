class Solution {
public:
    int reverse(int x) {
        int rev = 0, lastDigit;
        while (x) {
            lastDigit = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 or rev < INT_MIN / 10) {
                return 0;
            }
            rev = 10 * rev + lastDigit;
        }
        return rev;
    }
};