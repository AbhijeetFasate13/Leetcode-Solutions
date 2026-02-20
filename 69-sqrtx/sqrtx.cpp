class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        long long int l = -1, r = x;
        while (l + 1 < r) {
            long long int mid = l + (r - l) / 2;
            if (mid * mid <= x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};