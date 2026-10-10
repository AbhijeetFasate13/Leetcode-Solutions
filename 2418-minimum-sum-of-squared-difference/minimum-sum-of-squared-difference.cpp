class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        int mx = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            sum += 1LL * diff[i] * diff[i];
        }

        if (sum == 0) return 0;

        long long totalDiff = 0;
        for (int d : diff) totalDiff += d;

        if (k >= totalDiff) return 0;

        int lo = 0, hi = mx;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long ops = 0;

            for (int d : diff) {
                ops += max(0, d - mid);
            }

            if (ops <= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        int x = lo;
        long long ans = 0;
        long long used = 0;

        for (int d : diff) {
            int reduced = min(d, x);
            ans += 1LL * reduced * reduced;
            used += d - reduced;
        }

        long long remaining = k - used;

        for (int d : diff) {
            if (remaining == 0) break;

            if (d >= x && x > 0) {
                ans -= 1LL * x * x;
                ans += 1LL * (x - 1) * (x - 1);
                remaining--;
            }
        }

        return ans;
    }
};