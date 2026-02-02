class Solution {
    priority_queue<pair<int, int>> left;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>> right;
    unordered_set<int> used;
    int maxSz;
    long long currSum = 0;
    void cleanLeft() {
        while (!left.empty() && !used.count(left.top().second)) {
            left.pop();
        }
    }
    void cleanRight(int leftBound) {
        while (!right.empty() && right.top().second < leftBound) {
            right.pop();
        }
    }

public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        maxSz = k - 1;
        int n = nums.size();
        long long ans = LLONG_MAX;
        for (int r = 1; r < n; r++) {

            int l = r - dist - 1;
            if (l > 0 && used.count(l)) {
                used.erase(l);
                currSum -= nums[l];
                cleanRight(l);
                if (!right.empty()) {
                    auto [val, idx] = right.top();
                    right.pop();
                    left.push({val, idx});
                    used.insert(idx);
                    currSum += val;
                }
            }
            if ((int)used.size() < maxSz) {
                left.push({nums[r], r});
                used.insert(r);
                currSum += nums[r];
            } else {
                cleanLeft();
                if (!left.empty() && nums[r] < left.top().first) {
                    auto [val, idx] = left.top();
                    left.pop();
                    used.erase(idx);
                    left.push({nums[r], r});
                    used.insert(r);
                    currSum += nums[r] - val;
                    right.push({val, idx});

                } else {
                    right.push({nums[r], r});
                }
            }

            if (l >= 0) {
                ans = min(ans, currSum);
            }
        }

        return nums[0] + ans;
    }
};
