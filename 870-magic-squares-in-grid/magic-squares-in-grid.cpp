class Solution {
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        if (grid[row + 1][col + 1] != 5)
            return false;
        vector<int> isPresent(9);
        int sumCheck = -1, sum;
        for (int i = row; i < row + 3; i++) {
            sum = 0;
            for (int j = col; j < col + 3; j++) {
                int num = grid[i][j];
                if (num < 1 or num > 9)
                    return false;
                isPresent[num - 1]++;
                sum += num;
            }
            if (sumCheck == -1) {
                sumCheck = sum;
            } else if (sumCheck != sum) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (isPresent[i] == 0 or isPresent[i] > 1)
                return false;
        }
        for (int j = col; j < col + 3; j++) {
            sum = 0;
            for (int i = row; i < row + 3; i++) {
                sum += grid[i][j];
            }
            if (sum != sumCheck)
                return false;
        }
        sum = 0;
        int otherSum = 0;
        for (int i = 0; i < 3; i++) {
            sum += grid[row + i][col + i];
            otherSum += grid[row + i][col + 2 - i];
        }
        return sum == sumCheck and otherSum == sumCheck;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};