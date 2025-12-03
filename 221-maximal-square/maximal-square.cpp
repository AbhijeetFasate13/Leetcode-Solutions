class Solution {
    bool check(int mid, vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Build prefix sum matrix
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i + 1][j + 1] = (matrix[i][j] == '1') + pref[i][j + 1] +
                                     pref[i + 1][j] - pref[i][j];
            }
        }

        // Check every mid × mid submatrix
        for (int i = 0; i + mid <= n; i++) {
            for (int j = 0; j + mid <= m; j++) {
                int r1 = i, c1 = j;
                int r2 = i + mid, c2 = j + mid;

                int total =
                    pref[r2][c2] - pref[r1][c2] - pref[r2][c1] + pref[r1][c1];

                if (total == mid * mid) {
                    return true; // Found all-1 submatrix
                }
            }
        }

        return false;
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = min(m, n) + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(mid, matrix)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l*l;
    }
};