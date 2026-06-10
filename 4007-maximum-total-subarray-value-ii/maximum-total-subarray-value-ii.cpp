class Solution {
    vector<vector<int>> rmq, rmxq;
public:
    void buildSparse(const vector<int>& nums) {
        int n = nums.size();
        int LOG = log2(n) + 1;
        rmq.assign(n, vector<int>(LOG));
        rmxq.assign(n, vector<int>(LOG));
        for (int i = 0; i < n; i++) {
            rmq[i][0] = nums[i];
            rmxq[i][0] = nums[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
                rmxq[i][j] =
                    max(rmxq[i][j - 1], rmxq[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int queryMin(int l, int r) {
        int len = r - l + 1;
        int k = log2(len);

        return min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
    }

    int queryMax(int l, int r) {
        int len = r - l + 1;
        int k = log2(len);

        return max(rmxq[l][k], rmxq[r - (1 << k) + 1][k]);
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        buildSparse(nums);
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({queryMax(i, n - 1) - queryMin(i, n - 1), {i, n - 1}});
        }
        long long sum = 0;
        for (int i = 0; i < k && !pq.empty(); i++) {
            auto [val, range] = pq.top();
            pq.pop();
            auto [l, r] = range;
            sum += val;
            if (l < r) {
                pq.push({queryMax(l, r - 1) - queryMin(l, r - 1), {l, r - 1}});
            }
        }

        return sum;
    }
};