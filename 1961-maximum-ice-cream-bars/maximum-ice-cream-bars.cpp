class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxm = *max_element(costs.begin(), costs.end());
        vector<int> hash(maxm + 1);
        for (const int& i : costs) {
            hash[i]++;
        }
        int count = 0;
        for (int i = 0; i <= maxm; i++) {
            if (!hash[i])
                continue;
            while (coins - i >= 0 and hash[i]--) {
                coins -= i;
                count++;
            }
        }
        return count;
    }
};