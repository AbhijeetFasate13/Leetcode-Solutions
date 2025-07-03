class Solution {
    bool check(const vector<vector<long long>>& intervals, int dist) {
        long long last = intervals[0][0];

        for (int i = 1; i < intervals.size(); ++i) {
            long long curr = last + dist;
            if (curr > intervals[i][1])
                return false;
            last = max(curr, intervals[i][0]);
        }
        return true;
    }

    int solve(int n, vector<vector<long long>>& intervals) {
        sort(intervals.begin(), intervals.end());

        long long low = 0, high = 1e18, best = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(intervals, mid)) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return best;
    }

public:
    int maxPossibleScore(vector<int>& start, int d) {
        vector<vector<long long>> intervals;
        for (const auto& i : start) {
            intervals.push_back({i, i + d});
        }
        return solve(start.size(), intervals);
    }
};