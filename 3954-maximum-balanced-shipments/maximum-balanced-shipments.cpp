class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int count = 0;
        int n = weight.size();
        for (int i = 0; i < n - 1; i++) {
            if (weight[i] > weight[i + 1]) {
                count++;
                i++;
            }
        }
        return count;
    }
};