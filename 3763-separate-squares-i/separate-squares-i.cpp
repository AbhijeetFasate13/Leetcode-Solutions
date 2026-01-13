class Solution {
    double total;
    bool check(double mid, vector<vector<int>>& squares) {
        double areaBelow = 0.0;
        for (auto& s : squares) {
            double y = s[1];
            double side = s[2];
            double heightBelow = max(0.0, min(side, mid - y));
            areaBelow += heightBelow * side;
        }
        return areaBelow >= total / 2.0;
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        total = 0.0;
        double l = 2e9, r = 0.0;
        for (auto& s : squares) {
            double y = s[1];
            double side = s[2];
            total += side * side;
            l = min(l, y);
            r = max(r, y + side);
        }
        for (int i = 0; i < 100; ++i) {
            double mid = (l + r) / 2.0;
            if (check(mid, squares)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};
