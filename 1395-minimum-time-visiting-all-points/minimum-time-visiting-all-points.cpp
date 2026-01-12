class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> curr = points[0];
        int timeTaken = 0, diagonalMove, axisMove;
        for (int i = 1; i < n; i++) {
            diagonalMove =
                min(abs(points[i][0] - curr[0]), abs(points[i][1] - curr[1]));
            axisMove = abs(
                max(abs(points[i][0] - curr[0]), abs(points[i][1] - curr[1])) -
                diagonalMove);
            timeTaken += diagonalMove + axisMove;
            curr = points[i];
        }
        return timeTaken;
    }
};