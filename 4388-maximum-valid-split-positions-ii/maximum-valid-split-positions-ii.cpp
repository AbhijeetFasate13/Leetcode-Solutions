class Solution {
    vector<int> getPrefixGCD(const vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ans[i] = gcd(ans[i - 1], nums[i]);
        }
        return ans;
    }

    vector<int> getSuffixGCD(const vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = gcd(ans[i + 1], nums[i]);
        }
        return ans;
    }

    int maxPossibleWithOneDelete(const vector<int>& nums, int idx) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = (idx == 0 ? 0 : nums[0]);

        for (int i = 1; i < n; i++) {
            if (i == idx)
                prefix[i] = prefix[i - 1];
            else
                prefix[i] = gcd(prefix[i - 1], nums[i]);
        }

        vector<int> suffix(n);
        suffix[n - 1] = (idx == n - 1 ? 0 : nums[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            if (i == idx)
                suffix[i] = suffix[i + 1];
            else
                suffix[i] = gcd(suffix[i + 1], nums[i]);
        }

        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            if (i == idx)
                continue;

            if (prefix[i] == suffix[i + 1])
                count++;
        }

        return count;
    }

public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGCD = getPrefixGCD(nums);
        vector<int> suffixGCD = getSuffixGCD(nums);

        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            if (prefixGCD[i] == suffixGCD[i + 1])
                ans++;
        }

        set<int> trialIdx;

        trialIdx.insert(0);
        trialIdx.insert(n - 1);

        for (int i = 1; i < n - 1; i++) {
            if (prefixGCD[i] != prefixGCD[i - 1] ||
                suffixGCD[i] != suffixGCD[i + 1]) {
                trialIdx.insert(i);
            }
        }

        for (int idx : trialIdx) {
            ans = max(ans, maxPossibleWithOneDelete(nums, idx));
        }

        return ans;
    }
};
