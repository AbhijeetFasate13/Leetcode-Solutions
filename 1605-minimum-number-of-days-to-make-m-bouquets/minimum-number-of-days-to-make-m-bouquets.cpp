class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int n = bloomDay.size();
        long long a = m * 1ll, b = k * 1ll;
        long long check = a * b;
        if (check > n) {
            return -1;
        }
        auto fn = [&](int mid) {
            long int count = 0, flowers = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    flowers++;
                    if (flowers == k) {
                        count++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }
            return count >= m;
        };
        long int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (fn(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (int)l;
    }
};