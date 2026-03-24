class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, n = nums.size();
        long long prod = 1;
        int count = 0;
        for (int r = 0; r < n; r++) {
            prod *= nums[r];
            while (l <= r and prod >= k) {
                prod /= nums[l++];
            }
            count += (r - l + 1);
        }
        return count;
    }
};