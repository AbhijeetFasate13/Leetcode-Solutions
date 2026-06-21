class Solution {
    void countSort(vector<int>& costs) {
        unordered_map<int, int> hash;
        int maxm = INT_MIN;
        for (const int& i : costs) {
            hash[i]++;
            maxm = max(maxm, i);
        }
        int ptr = 0;
        for (int i = 0; i <= maxm; i++) {
            if (!hash.count(i))
                continue;
            while (hash[i]--) {
                costs[ptr++] = i;
            }
        }
    }

public:
    int maxIceCream(vector<int>& costs, int coins) {
        countSort(costs);
        int count = 0;
        for (const int& i : costs) {
            if (coins - i >= 0) {
                count++;
                coins -= i;
            }
        }
        return count;
    }
};