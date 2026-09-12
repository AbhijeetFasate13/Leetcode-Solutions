class Solution {
private:
    using State = pair<long long, vector<int>>;

    vector<tuple<int, int, int>> intervals;
    vector<int> nextIndex;
    vector<vector<State>> dp;
    map<tuple<int, int, int>, int> originalIndex;

    State solve(int index, int remaining) {
        if (index == intervals.size() || remaining == 0) {
            return {0, {}};
        }

        if (dp[index][remaining].first != -1) {
            return dp[index][remaining];
        }

        State skip = solve(index + 1, remaining);

        auto [start, end, weight] = intervals[index];

        State take = solve(nextIndex[index], remaining - 1);
        take.first -= weight;
        take.second.push_back(originalIndex[{start, end, weight}]);

        sort(take.second.begin(), take.second.end());

        return dp[index][remaining] = min(skip, take);
    }

    void removeDuplicates(const vector<vector<int>>& input) {
        for (int index = 0; index < input.size(); ++index) {
            tuple<int, int, int> interval = {input[index][0], input[index][1],
                                             input[index][2]};

            if (!originalIndex.contains(interval)) {
                originalIndex[interval] = index;
            }
        }
    }

    void buildIntervals() {
        for (const auto& [interval, index] : originalIndex) {
            intervals.push_back(interval);
        }
    }

    void buildNextIndices() {
        nextIndex.resize(intervals.size());

        for (int index = 0; index < intervals.size(); ++index) {
            auto [start, end, weight] = intervals[index];

            nextIndex[index] = upper_bound(intervals.begin(), intervals.end(),
                                           make_tuple(end, INT_MAX, INT_MAX)) -
                               intervals.begin();
        }
    }

    void initializeDp() {
        dp.assign(intervals.size(), vector<State>(5, {-1, {}}));
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& input) {
        removeDuplicates(input);
        buildIntervals();
        buildNextIndices();
        initializeDp();

        return solve(0, 4).second;
    }
};