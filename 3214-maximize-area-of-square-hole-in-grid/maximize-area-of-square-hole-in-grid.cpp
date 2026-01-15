class Solution {
    int getStreak(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int streak = 1, len = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1] + 1) {
                len++;
            } else {
                streak = max(len, streak);
                len = 1;
            }
        }
        streak = max(len, streak);
        return streak;
    }

public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        return pow(min(getStreak(hBars), getStreak(vBars)) + 1,2);
    }
};