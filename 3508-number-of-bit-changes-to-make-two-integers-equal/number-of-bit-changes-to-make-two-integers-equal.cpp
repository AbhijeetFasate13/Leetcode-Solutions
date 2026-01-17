class Solution {
public:
    int minChanges(int n, int k) {
        int changes = 0;
        for (int i = 0; i < 32; i++) {
            int nBit = (n >> i) & 1;
            int kBit = (k >> i) & 1;
            if (nBit == 0 and kBit == 1)
                return -1;
            if (nBit == kBit)
                continue;
            changes++;
        }
        return changes;
    }
};