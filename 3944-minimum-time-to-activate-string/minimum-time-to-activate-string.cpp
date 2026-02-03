class Solution {
    bool check(const string& s, const int& time, vector<int>& order,
               const int& k) {
        string now = s;
        for (int i = 0; i <= time; i++) {
            now[order[i]] = '*';
        }
        int n = now.size();
        long long int total = (n * (n + 1ll)) / 2;
        long long int curr = 0;
        for (int i = 0; i < n; i++) {
            if (now[i] != '*') {
                curr++;
            } else {
                total -= (curr * (curr + 1)) / 2;
                curr = 0;
            }
        }
        total -= (curr * (curr + 1)) / 2;
        return total >= k;
    }

public:
    int minTime(string s, vector<int>& order, int k) {
        int r = order.size();
        if ((r * 1ll * (r + 1)) / 2 < k)
            return -1;
        int l = -1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (check(s, mid, order, k)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};