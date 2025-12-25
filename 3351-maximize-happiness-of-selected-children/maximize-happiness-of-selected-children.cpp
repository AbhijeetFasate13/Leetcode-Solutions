class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int decrement = 0;
        sort(begin(happiness), end(happiness), greater<int>());
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            if (happiness[i] + decrement <= 0)
                continue;
            ans += happiness[i] + decrement;
            decrement--;
        }
        return ans;
    }
};