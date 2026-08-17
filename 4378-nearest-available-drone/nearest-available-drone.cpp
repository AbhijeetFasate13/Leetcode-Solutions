class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int idx = -1, nearestDist = INT_MAX;
        int n = drones.size();
        int a = target[0], b = target[1];
        for (int i = 0; i < n; i++) {
            int x = drones[i][0], y = drones[i][1], range = drones[i][2];
            int dist = abs(x - a) + abs(y - b);
            if (dist <= range and nearestDist > dist) {
                nearestDist = dist;
                idx = i;
            }
        }
        return idx;
    }
};