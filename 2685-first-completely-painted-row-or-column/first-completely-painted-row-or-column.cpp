class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<int> rowCount(m, 0), colCount(n, 0);
        unordered_map<int, int> position;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                position[mat[i][j]] = i * n + j;
            }
        }
        int idx, row, col;
        for (int i = 0; i < arr.size(); i++) {
            idx = position[arr[i]];
            col = idx % n;
            row = (idx - col) / n;
            rowCount[row]++;
            colCount[col]++;
            if (rowCount[row] == n || colCount[col] == m)
                return i;
        }

        return -1;
    }
};