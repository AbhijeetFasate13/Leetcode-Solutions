class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int a = 0, b = 0;
        int m = nums1.size(), n = nums2.size();
        while (a != m and b != n) {
            if (nums1[a] == nums2[b])
                return nums1[a];
            if (nums1[a] < nums2[b])
                a++;
            else
                b++;
        }
        return -1;
    }
};