class Solution {
    const int mod = 1337;
    vector<int> dividedByTwo(const vector<int>& arr) {
        vector<int> result;
        int rem = 0;
        for (int digit : arr) {
            int num = rem * 10 + digit;
            result.push_back(num / 2);
            rem = num % 2;
        }
        while (!result.empty() && result[0] == 0) {
            result.erase(result.begin());
        }
        return result;
    }

public:
    int superPow(int a, vector<int>& b) {
        a %= mod;
        int res = 1;
        while (!b.empty()) {
            if (b.back() % 2 == 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b = dividedByTwo(b);
        }
        return res;
    }
};
