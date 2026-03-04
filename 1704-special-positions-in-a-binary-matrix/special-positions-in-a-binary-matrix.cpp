class Solution {
    bool checkRowCol(const int& i, const int& j, const int& m, const int& n,
                     vector<vector<int>>& mat) {
        for (int k = 0; k < n; k++) {
            if (k == j)
                continue;
            if (mat[i][k] == 1)
                return false;
        }
        for (int k = 0; k < m; k++) {
            if (k == i)
                continue;
            if (mat[k][j] == 1)
                return false;
        }
        return true;
    }

public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int count = 0;
        vector<bool> col(n, true);
        bool rowColSafe;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!col[j])
                    continue;
                if (mat[i][j] == 1) {
                    rowColSafe = checkRowCol(i, j, m, n, mat);
                    if (rowColSafe)
                        count++;
                    else {
                        col[j] = false;
                        break;
                    }
                }
            }
        }
        return count;
    }
};