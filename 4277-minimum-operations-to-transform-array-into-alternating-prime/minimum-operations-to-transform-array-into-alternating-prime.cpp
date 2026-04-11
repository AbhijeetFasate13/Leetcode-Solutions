class Solution {
    const int MAXM = 100005;
    vector<int> isPrime, nextPrime;

public:
    Solution() {
        isPrime.assign(MAXM, 1);
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i * i < MAXM; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < MAXM; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        nextPrime.resize(MAXM);
        int last = -1;
        for (int i = MAXM - 1; i >= 0; i--) {
            if (isPrime[i])
                last = i;
            nextPrime[i] = last;
        }
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cost = 0, x;
        for (int i = 0; i < n; i++) {
            x = nums[i];
            if (i % 2 == 0)
                cost += nextPrime[x] - x;
            else
                cost += isPrime[x] ? (x == 2 ? 2 : 1) : 0;
        }
        return cost;
    }
};