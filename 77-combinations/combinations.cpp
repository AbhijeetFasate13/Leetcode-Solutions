class Solution {
    void rec(const int& n, const int& k, const int& level,
             vector<int>& currComb, vector<vector<int>>& allComb) {
        if (level == k) {
            allComb.push_back(currComb);
            return;
        }
        for (int i = (level == 0 ? 1 : currComb.back() + 1); i <= n; i++) {
            currComb.push_back(i);
            rec(n, k, level + 1, currComb, allComb);
            currComb.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> currComb;
        vector<vector<int>> allComb;
        rec(n, k, 0, currComb, allComb);
        return allComb;
    }
};