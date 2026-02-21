class Solution {
    bool checkRow(int row, const vector<vector<char>>& board) {
        vector<int> numbers(10);
        char c;
        for (int col = 0; col < 9; col++) {
            c = board[row][col];
            if (c == '.')
                continue;
            if (numbers[c - '0']) {
                return false;
            }
            numbers[c - '0']++;
        }
        return true;
    }
    bool checkCol(int col, const vector<vector<char>>& board) {
        vector<int> numbers(10);
        char c;
        for (int row = 0; row < 9; row++) {
            c = board[row][col];
            if (c == '.')
                continue;
            if (numbers[c - '0']) {
                return false;
            }
            numbers[c - '0']++;
        }
        return true;
    }
    bool checkSub(int row, int col, const vector<vector<char>>& board) {
        vector<int> numbers(10);
        char c;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                c = board[i][j];
                if (c == '.')
                    continue;
                if (numbers[c - '0']) {
                    return false;
                }
                numbers[c - '0']++;
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!checkRow(i, board) or !checkCol(i, board)) {
                return false;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!checkSub(i, j, board)) {
                    return false;
                }
            }
        }
        return true;
    }
};