class Solution {
    int calcUBound(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.begin() + n - k + 1, 0);
        int minSum = sum;
        for (int i = n - k + 1; i < n; i++) {
            sum += nums[i];
            sum -= nums[i - n + k - 1];
            minSum = min(minSum, sum);
        }
        return minSum;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = (int)nums.size();
        auto fn = [&](int mid) {
            int count = 1;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] <= mid) {
                    sum += nums[i];
                } else {
                    count++;
                    sum = nums[i];
                }
            }
            return count <= k;
        };
        int l = *max_element(nums.begin(), nums.end()),
            r = accumulate(nums.begin(), nums.end(), 0);
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (fn(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};