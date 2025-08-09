class Solution {

public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        int highestPowOfThree = log(INT_MAX) / log(3);
        return (int)pow(3, highestPowOfThree) % n == 0;
    }
};