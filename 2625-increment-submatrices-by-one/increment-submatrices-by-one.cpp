class Solution {
    void updateMat(const vector<int>& q, vector<vector<int>>& mat) {
        int r1 = q[0];
        int c1 = q[1];
        int r2 = q[2];
        int c2 = q[3];
        int n = mat.size();
        mat[r1][c1] += 1;
        if (r2 + 1 < n) {
            mat[r2 + 1][c1] -= 1;
        }
        if (c2 + 1 < n) {
            mat[r1][c2 + 1] -= 1;
        }
        if (r2 + 1 < n and c2 + 1 < n) {
            mat[r2 + 1][c2 + 1] += 1;
        }
    }
    void prefixRow(vector<vector<int>>& mat) {
        for (auto& row : mat) {
            for (int i = 1; i < row.size(); i++) {
                row[i] += row[i - 1];
            }
        }
    }
    void prefixCol(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                mat[j][i] += mat[j - 1][i];
            }
        }
    }

public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n));
        for (const auto& q : queries) {
            updateMat(q, mat);
        }
        prefixRow(mat);
        prefixCol(mat);
        return mat;
    }
};