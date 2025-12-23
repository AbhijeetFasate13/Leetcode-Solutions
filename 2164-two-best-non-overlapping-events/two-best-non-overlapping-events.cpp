class Solution {
    int binarySearch(vector<vector<int>>& events, int i) {
        int target = events[i][1] + 1;
        int l = i, r = events.size();
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] < target)
                l = mid;
            else
                r = mid;
        }
        return r;
    }

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, events[i][2]);

            int j = binarySearch(events, i);
            if (j < n) {
                ans = max(ans, events[i][2] + suffixMax[j]);
            }
        }
        return ans;
    }
};
