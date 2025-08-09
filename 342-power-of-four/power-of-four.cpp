class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        string maskBinary = "01010101010101010101010101010101";
        int mask = stol(maskBinary, nullptr, 2);
        return (n & mask) == n && __builtin_popcount(n)==1;
    }
};