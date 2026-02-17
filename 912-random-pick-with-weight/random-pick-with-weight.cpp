class Solution {
    vector<int> original;
    vector<int> prefix;
    int total;

public:
    Solution(vector<int>& w) {
        original = w;
        prefix = w;
        int n = w.size();
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + w[i];
        }
        total = prefix.back();
    }

    int pickIndex() {
        int prefixSum = rand() % total + 1;
        int idx = lower_bound(prefix.begin(), prefix.end(), prefixSum) -
                  prefix.begin();
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */