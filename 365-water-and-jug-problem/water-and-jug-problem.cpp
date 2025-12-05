class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        return (target % (__gcd(x, y)) == 0) and ((x + y) >= target);
    }
};