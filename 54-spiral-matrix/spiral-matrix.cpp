class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = (int)matrix.size(), m = (int)matrix[0].size();
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> finalAns;
        int x = 0, y = 0, ptr = 0;
        finalAns.push_back(matrix[x][y]);
        matrix[x][y] = INT_MIN;
        for (int i = 1; i < n * m; i++) {
            int newX = x + dir[ptr].first, newY = y + dir[ptr].second;
            if (newX >= n or newX < 0 or newY >= m or newY < 0 or
                matrix[newX][newY] == INT_MIN) {
                ptr++;
                ptr %= 4;
                newX = x + dir[ptr].first, newY = y + dir[ptr].second;
            }
            x = newX, y = newY;
            finalAns.push_back(matrix[x][y]);
            matrix[x][y] = INT_MIN;
        }
        return finalAns;
    }
};