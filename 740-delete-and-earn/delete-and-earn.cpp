class Solution {
    vector<int> dp;

    vector<int> getFreqMap(const vector<int>& nums) {
        int maxi = *max_element(begin(nums), end(nums));
        vector<int> freq(maxi + 1, 0);
        for (int x : nums) {
            freq[x]++;
        }
        return freq;
    }
    int performOps(int i, vector<int>& freq) {
        if (i >= freq.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int skip = performOps(i + 1, freq);
        int take = freq[i] * i + performOps(i + 2, freq);

        return dp[i] = max(take, skip);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> freq = getFreqMap(nums);
        dp.assign(freq.size() + 1, -1);
        return performOps(1, freq);
    }
};
