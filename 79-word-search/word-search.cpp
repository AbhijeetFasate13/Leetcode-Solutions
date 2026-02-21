class Solution {
public:
    bool helper(int row, int col, int idx, const string& cmp,
                vector<vector<char>>& given, vector<vector<bool>>& visited) {
        if (idx == cmp.size())
            return true;
        int n = given.size(), m = given[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m || visited[row][col] ||
            given[row][col] != cmp[idx])
            return false;

        visited[row][col] = true;
        if (helper(row + 1, col, idx + 1, cmp, given, visited) ||
            helper(row - 1, col, idx + 1, cmp, given, visited) ||
            helper(row, col + 1, idx + 1, cmp, given, visited) ||
            helper(row, col - 1, idx + 1, cmp, given, visited)) {
            return true;
        }
        visited[row][col] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    if (helper(i, j, 0, word, board, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
