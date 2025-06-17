class Solution {
public:
    int hammingWeight(int n) {
        int setBits = 0;
        while (n) {
            if (n & 1) {
                setBits++;
            }
            n >>= 1;
        }
        return setBits;
    }
};