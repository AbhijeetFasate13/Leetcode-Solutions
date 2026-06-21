class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        unordered_map<int, int> hash;
        for (auto& i : costs) {
            hash[i]++;
        }
        int ptr = 0;
        for (int i = 0; i < 1e5 + 1; i++) {
            while (hash[i]--) {
                costs[ptr++] = i;
            }
        }
        int count = 0;
        for (auto& i : costs) {
            if (coins - i >= 0) {
                count++;
                coins -= i;
            }
        }
        return count;
    }
};