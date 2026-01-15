class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));
        int streakH = 1, streakV = 1, len = 1;
        for (int i = 1; i < hBars.size(); i++) {
            // if (hBars[i] == n + 2)
            //     continue;
            if (hBars[i] == hBars[i - 1] + 1) {
                len++;
            } else {
                streakH = max(len, streakH);
                len = 1;
            }
        }
        streakH = max(len, streakH);
        len = 1;
        for (int i = 1; i < vBars.size(); i++) {
            // if (vBars[i] == m + 2)
            //     continue;
            if (vBars[i] == vBars[i - 1] + 1) {
                len++;
            } else {
                streakV = max(len, streakV);
                len = 1;
            }
        }
        streakV = max(len, streakV);
        return pow((min(streakH, streakV) + 1), 2);
    }
};