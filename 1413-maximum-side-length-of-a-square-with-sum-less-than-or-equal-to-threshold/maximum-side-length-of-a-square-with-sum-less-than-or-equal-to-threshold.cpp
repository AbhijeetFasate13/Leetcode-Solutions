class Solution {
    vector<vector<int>> prefix;
    int rows, cols;
    void pre(const vector<vector<int>>& mat) {
        prefix.assign(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] = (i > 0 ? prefix[i - 1][j] : 0) +
                               (j > 0 ? prefix[i][j - 1] : 0) -
                               ((i > 0 and j > 0) ? prefix[i - 1][j - 1] : 0) +
                               mat[i][j];
            }
        }
    }

    bool check(const int& row, const int& col, const int& sz,
               const int& threshold) {
        int sumOfSquare = prefix[row + sz - 1][col + sz - 1] -
                          (col > 0 ? prefix[row + sz - 1][col - 1] : 0) -
                          (row > 0 ? prefix[row - 1][col + sz - 1] : 0) +
                          (row > 0 and col > 0 ? prefix[row - 1][col - 1] : 0);
        return sumOfSquare <= threshold;
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        rows = mat.size(), cols = mat[0].size();
        int ans = 0;
        pre(mat);
        for (int sz = 1; sz <= min(rows, cols); sz++) {
            bool isSideLengthUnderThreshold = false;
            for (int i = 0; i <= rows - sz; i++) {
                for (int j = 0; j <= cols - sz; j++) {
                    if (check(i, j, sz, threshold)) {
                        isSideLengthUnderThreshold = true;
                        break;
                    }
                }
                if (isSideLengthUnderThreshold) {
                    break;
                }
            }
            if (isSideLengthUnderThreshold) {
                ans = sz;
            }
        }
        return ans;
    }
};