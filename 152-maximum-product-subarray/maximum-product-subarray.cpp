class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref = 1, suff = 1, maxi = nums[0];
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            pref = (pref == 0 ? nums[i] : pref * nums[i]);
            suff = (suff == 0 ? nums[n - 1 - i] : suff * nums[n - 1 - i]);
            maxi = max({maxi, pref, suff});
        }

        return maxi;
    }
};
