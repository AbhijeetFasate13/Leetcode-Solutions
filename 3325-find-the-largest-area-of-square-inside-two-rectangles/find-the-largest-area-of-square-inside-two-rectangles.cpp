class Solution {
    static long long maxSquareIntersection(int ax1, int ay1, int ax2, int ay2,
                                           int bx1, int by1, int bx2, int by2) {
        int x1 = max(ax1, bx1);
        int y1 = max(ay1, by1);
        int x2 = min(ax2, bx2);
        int y2 = min(ay2, by2);

        int side = min(x2 - x1, y2 - y1);
        if (side <= 0)
            return 0;

        return 1LL * side * side;
    }

public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long result = 0;

        for (int i = 0; i < n; i++) {
            int ax1 = bottomLeft[i][0];
            int ay1 = bottomLeft[i][1];
            int ax2 = topRight[i][0];
            int ay2 = topRight[i][1];

            for (int j = i + 1; j < n; j++) {
                result = max(result, maxSquareIntersection(
                                         ax1, ay1, ax2, ay2, bottomLeft[j][0],
                                         bottomLeft[j][1], topRight[j][0],
                                         topRight[j][1]));
            }
        }
        return result;
    }
};
