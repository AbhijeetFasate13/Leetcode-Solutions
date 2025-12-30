class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        vector<vector<int>> mergedIntervals;
        vector<int> currInterval = intervals[0];
        int currEnd = intervals[0][1];
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            if (end <= currEnd)
                continue;
            if (start <= currEnd) {
                currInterval.back() = end;
                currEnd = end;
            } else {
                mergedIntervals.push_back(currInterval);
                currInterval = intervals[i];
                currEnd = currInterval.back();
            }
        }
        mergedIntervals.push_back(currInterval);
        return mergedIntervals;
    }
};