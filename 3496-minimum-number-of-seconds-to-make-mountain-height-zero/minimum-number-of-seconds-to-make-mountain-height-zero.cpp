class Solution {
public:
    long long check(long long t, vector<int>& workerTimes) {
        long long x = 0;
        for (int w : workerTimes)
            x += (long long)((sqrt(1 + 8.0 * t / w) - 1) / 2);
        return x;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int wz = workerTimes.size();
        if (wz == 1)
            return (long long)workerTimes[0] * mountainHeight *
                   (mountainHeight + 1) / 2;
        long long l = 0, r = 1e12;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            long long x = check(m, workerTimes);
            if (x >= mountainHeight)
                r = m;
            else
                l = m;
        }
        return r;
    }
};