class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0 or n % 2 == 0 or (n % 3 != 0 and n != 1))
            return false;
        if (n == 1)
            return true;
        return isPowerOfThree(n / 3);
    }
};