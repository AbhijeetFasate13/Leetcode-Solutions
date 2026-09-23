class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> prefix, suffix;
        prefix[0] = -1, suffix[0] = -1;
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefix[sum] = i;
        }

        sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[n - 1 - i];
            suffix[sum] = i;
        }

        int minm = INT_MAX, idx1, idx2;

        for (const auto& i : prefix) {
            if (i.first > x)
                continue;
            if (suffix.count(x - i.first)) {
                idx1 = i.second, idx2 = suffix[x - i.first];
                if (idx1 + idx2 + 2 <= n) {
                    minm = min(minm, idx1 + idx2 + 2);
                }
            }
        }
        return minm == INT_MAX ? -1 : minm;
    }
};