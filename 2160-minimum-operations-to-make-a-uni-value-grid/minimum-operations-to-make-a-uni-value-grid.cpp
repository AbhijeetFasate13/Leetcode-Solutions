class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> a;
        for (auto& row : grid)
            for (int v : row)
                a.push_back(v);

        int mod = a[0] % x;
        for (int v : a) {
            if (v % x != mod)
                return -1;
        }

        sort(a.begin(), a.end());
        int median = a[a.size() / 2];

        int ops = 0;
        for (int v : a) {
            ops += abs(v - median) / x;
        }
        return ops;
    }
};