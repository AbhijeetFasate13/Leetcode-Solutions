class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long squareSum = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    vector<int> last;

    void apply(int node, int start, int end, long long x) {
        long long len = end - start + 1;

        tree[node].squareSum = (tree[node].squareSum +
                                2LL * x * tree[node].sum + x * x % MOD * len) %
                               MOD;

        tree[node].sum = (tree[node].sum + len * x) % MOD;

        tree[node].lazy = (tree[node].lazy + x) % MOD;
    }

    void push(int node, int start, int end) {
        if (tree[node].lazy == 0 || start == end) {
            return;
        }

        int mid = start + (end - start) / 2;
        long long x = tree[node].lazy;

        apply(2 * node, start, mid, x);
        apply(2 * node + 1, mid + 1, end, x);

        tree[node].lazy = 0;
    }

    void pull(int node) {
        tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % MOD;

        tree[node].squareSum =
            (tree[2 * node].squareSum + tree[2 * node + 1].squareSum) % MOD;
    }

    void update(int node, int start, int end, int left, int right) {
        if (right < start || end < left) {
            return;
        }

        if (left <= start && end <= right) {
            apply(node, start, end, 1);
            return;
        }

        push(node, start, end);

        int mid = start + (end - start) / 2;

        update(2 * node, start, mid, left, right);
        update(2 * node + 1, mid + 1, end, left, right);

        pull(node);
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        tree.assign(4 * n + 1, Node());
        last.assign(1e5 + 1, -1);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int left = last[nums[i]] + 1;
            last[nums[i]] = i;

            update(1, 0, n - 1, left, i);

            ans = (ans + tree[1].squareSum) % MOD;
        }

        return ans;
    }
};