class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        int rev = 0, lastDigit;
        bool isNeg = x < 0 ? true : false;
        if (isNeg)
            x *= -1;
        while (x) {
            lastDigit = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 or rev < INT_MIN / 10) {
                return 0;
            }
            rev = 10 * rev + lastDigit;
        }
        return isNeg ? -rev : rev;
    }
};