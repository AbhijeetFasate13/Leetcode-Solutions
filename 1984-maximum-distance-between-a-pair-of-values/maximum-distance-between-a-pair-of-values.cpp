class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxm = 0;
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        while (i < m and j < n) {
            if (nums1[i] <= nums2[j]) {
                maxm = max(maxm, j - i);
                j++;
            } else {
                i++;
            }
        }
        return maxm;
    }
};