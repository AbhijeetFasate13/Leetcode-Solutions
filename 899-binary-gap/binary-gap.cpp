class Solution {
public:
    int binaryGap(int n) {
        int gap = 0, maxGap = 0;
        bool foundFirstSetBit = false;
        while (n) {
            if (n & 1) {
                maxGap = max(maxGap, gap);
                gap = 1;
                if (!foundFirstSetBit)
                    foundFirstSetBit = true;
            } else if (foundFirstSetBit) {
                gap++;
            }
            n >>= 1;
        }
        return maxGap;
    }
};