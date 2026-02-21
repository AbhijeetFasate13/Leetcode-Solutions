class Solution {
public:
    bool helper(int row, int col, int idx, const string& cmp,
                vector<vector<char>>& given) {
        if (idx == cmp.size())
            return true;
        if (row < 0 || row == given.size() || col < 0 ||
            col == given[0].size() || given[row][col] != cmp[idx])
            return false;

        char c = given[row][col];
        given[row][col] = '#';
        if (helper(row + 1, col, idx + 1, cmp, given) ||
            helper(row - 1, col, idx + 1, cmp, given) ||
            helper(row, col + 1, idx + 1, cmp, given) ||
            helper(row, col - 1, idx + 1, cmp, given)) {
            return true;
        }
        given[row][col] = c;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    if (helper(i, j, 0, word, board)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
