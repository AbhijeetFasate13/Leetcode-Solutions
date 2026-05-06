class Solution {
    int m, n;
    void moveObjectsToRight(vector<vector<char>>& box) {
        for (int i = 0; i < m; i++) {
            int empty = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    empty = j - 1;
                }
                else if (box[i][j] == '#') {
                    swap(box[i][j], box[i][empty]);
                    empty--;
                }
            }
        }
    }
    vector<vector<char>> rotate90(vector<vector<char>>& box) {
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - 1 - i] = box[i][j];
            }
        }
        return ans;
    }

public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        m = box.size();
        n = box[0].size();
        moveObjectsToRight(box);
        return rotate90(box);
    }
};