class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        unordered_map<int, int> hash;
        int maxm = INT_MIN;
        for (const int& i : costs) {
            hash[i]++;
            maxm = max(maxm, i);
        }
        int count = 0;
        for (int i = 0; i <= maxm; i++) {
            if (!hash.count(i))
                continue;
            while (coins - i >= 0 and hash[i]--) {
                coins -= i;
                count++;
            }
        }
        return count;
    }
};