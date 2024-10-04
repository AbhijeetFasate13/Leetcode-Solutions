class Solution {
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