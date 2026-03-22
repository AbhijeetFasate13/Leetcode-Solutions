class Solution {
    vector<vector<int>> transpose(vector<vector<int>> mat) {
        int n = mat.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        return mat;
    }

    vector<vector<int>> reverseRows(vector<vector<int>> mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
        return mat;
    }

    vector<vector<int>> rotate90degree(vector<vector<int>> mat) {
        return reverseRows(transpose(mat));
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (mat == target)
                return true;
            mat = rotate90degree(mat);
        }
        return false;
    }
};