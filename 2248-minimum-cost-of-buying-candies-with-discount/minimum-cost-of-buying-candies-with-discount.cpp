class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int n = cost.size();
        int totalCost = 0;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 3 == 0)
                continue;
            totalCost += cost[i];
        }
        return totalCost;
    }
};