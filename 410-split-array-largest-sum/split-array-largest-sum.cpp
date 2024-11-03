class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = (int)nums.size();
        auto fn = [&](int mid) {
            int groups = 0;
            int temp = mid;
            for (int i = 0; i < n; i++) {
                if (temp - nums[i] >= 0) {
                    temp -= nums[i];
                } else {
                    groups++;
                    temp = mid - nums[i];
                }
            }
            return groups >= k;
        };
        int l = *max_element(nums.begin(), nums.end()) - 1;
        int r = accumulate(nums.begin(), nums.end(), 0) + 1;
        while (l + 1 < r) {
            int mid = l + (r - l + 1) / 2;
            if (fn(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return r;
    }
};