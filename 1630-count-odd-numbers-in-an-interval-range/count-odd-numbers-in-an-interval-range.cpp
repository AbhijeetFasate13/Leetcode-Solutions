class Solution {
public:
    int countOdds(int low, int high) {
        int len = high - low + 1;
        if (len & 1) {
            return len / 2 + (low & 1);
        }
        return len / 2;
    }
};