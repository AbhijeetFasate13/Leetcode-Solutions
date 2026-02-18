class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev, curr, itr = 0;
        while (n) {
            curr = n & 1;
            if (itr > 0 and prev == curr) {
                return false;
            }
            itr++;
            prev = curr;
            n >>= 1;
        }
        return true;
    }
};