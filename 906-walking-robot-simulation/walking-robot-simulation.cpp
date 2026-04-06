class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for (const auto &o : obstacles) {
            st.insert(to_string(o[0]) + "," + to_string(o[1]));
        }
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int x = 0, y = 0;
        int currDir = 0;
        int maxDist = 0;
        for (const int& cmd : commands) {
            if (cmd == -1) {
                currDir = (currDir + 1) % 4;
            } 
            else if (cmd == -2) {
                currDir = (currDir + 3) % 4;
            } 
            else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dir[currDir][0];
                    int ny = y + dir[currDir][1];
                    if (st.count(to_string(nx) + "," + to_string(ny))) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        return maxDist;
    }
};