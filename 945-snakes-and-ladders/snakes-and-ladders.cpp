class Solution {
    unordered_map<int, int> calculateJumps(const vector<vector<int>>& board) {
        unordered_map<int, int> mp;
        int n = board.size();
        int tileNum = 1;
        bool leftToRight = true;
        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] != -1)
                        mp[tileNum] = board[i][j];
                    tileNum++;
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] != -1)
                        mp[tileNum] = board[i][j];
                    tileNum++;
                }
            }
            leftToRight = !leftToRight;
        }
        return mp;
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int, int> jump = calculateJumps(board);
        int n = board.size();
        int target = n * n;
        queue<int> q;
        q.push(1);
        vector<bool> visited(target + 1, false);
        visited[1] = true;
        int rolls = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int curr = q.front();
                q.pop();
                if (curr == target)
                    return rolls;
                for (int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;
                    if (next > target)
                        break;
                    if (jump.count(next))
                        next = jump[next];
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            rolls++;
        }
        return -1;
    }
};