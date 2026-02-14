class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prev = {(double)poured};
        for (int row = 0; row < query_row; row++) {
            vector<double> curr(prev.size() + 1, 0.0);
            for (int col = 0; col < prev.size(); col++) {
                if (prev[col] > 1.0) {
                    double overflow = (prev[col] - 1.0) / 2.0;
                    curr[col] += overflow;
                    curr[col + 1] += overflow;
                }
            }
            prev = curr;
        }
        return min(1.0, prev[query_glass]);
    }
};
