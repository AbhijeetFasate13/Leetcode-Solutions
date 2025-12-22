class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char, long long int> totalCostPerChar;
        long long int maxx = 0;
        for (int i = 0; i < s.size(); i++) {
            totalCostPerChar[s[i]] += cost[i];
            maxx = max(maxx, totalCostPerChar[s[i]]);
        }
        return accumulate(begin(cost), end(cost), 0ll) - maxx;
    }
};