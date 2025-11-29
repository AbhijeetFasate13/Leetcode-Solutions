class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int)cost.size();
        if (n == 1) {
            return 0;
        }
        int a = 0, b = 0, c;
        for (int i = 2; i <= n; i++) {
            c = min(b + cost[i - 1], a + cost[i - 2]);
            a = b;
            b = c;
        }
        return c;
    }
};