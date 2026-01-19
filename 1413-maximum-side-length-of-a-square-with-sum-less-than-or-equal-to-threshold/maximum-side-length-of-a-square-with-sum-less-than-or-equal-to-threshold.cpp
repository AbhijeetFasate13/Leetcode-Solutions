static auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    vector<vector<int>> prefix;
    int rows, cols;

    void buildPrefix(const vector<vector<int>>& mat) {
        prefix.assign(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] = mat[i][j] + (i > 0 ? prefix[i - 1][j] : 0) +
                               (j > 0 ? prefix[i][j - 1] : 0) -
                               (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }
    }

    bool validSquare(int r, int c, int sz, int threshold) {
        int sum = prefix[r + sz - 1][c + sz - 1] -
                  (r > 0 ? prefix[r - 1][c + sz - 1] : 0) -
                  (c > 0 ? prefix[r + sz - 1][c - 1] : 0) +
                  (r > 0 && c > 0 ? prefix[r - 1][c - 1] : 0);

        return sum <= threshold;
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        if (mat.empty() || mat[0].empty())
            return 0;

        rows = mat.size();
        cols = mat[0].size();

        buildPrefix(mat);

        int l = 0, r = min(rows, cols);

        while (l < r) {
            int m = l + (r - l + 1) / 2;
            bool ok = false;

            for (int i = 0; i + m <= rows && !ok; i++) {
                for (int j = 0; j + m <= cols; j++) {
                    if (validSquare(i, j, m, threshold)) {
                        ok = true;
                        break;
                    }
                }
            }

            if (ok)
                l = m;
            else
                r = m-1;
        }

        return l;
    }
};
