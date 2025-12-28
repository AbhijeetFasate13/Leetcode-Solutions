class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> spiralMatrix(rows * cols);
        int r = 0, c = 0, ptr = 0;
        spiralMatrix[0] = matrix[r][c];
        matrix[r][c] = -101;
        for (int i = 1; i < rows * cols; i++) {
            int nR = r + dir[ptr][0], nC = c + dir[ptr][1];
            if (nR == -1 or nR == rows or nC == -1 or nC == cols or
                matrix[nR][nC] == -101) {
                ptr += 1;
                ptr %= 4;
                nR = r + dir[ptr][0];
                nC = c + dir[ptr][1];
            }
            r = nR;
            c = nC;
            spiralMatrix[i] = matrix[r][c];
            matrix[r][c] = -101;
        }
        return spiralMatrix;
    }
};