class Solution {
public:
    int minRemoval(vector<int>& nums, int K) {
        long long k = K;
        int n = nums.size();
        int minm = n - 1;
        sort(begin(nums), end(nums));
        int toRemove;
        for (int i = 0; i < n; i++) {
            // assuming curr idx to be min
            toRemove = n - (upper_bound(nums.begin(), nums.end(), nums[i] * k) -
                            nums.begin());
            minm = min(minm, i + toRemove);
            // assuming curr idx to be max
            toRemove = upper_bound(nums.begin(), nums.end(),
                                   ceil((nums[i] * 1.0) / k)) -
                       nums.begin() - 1;
            minm = min(minm, n - i + toRemove);
        }
        return minm;
    }
};