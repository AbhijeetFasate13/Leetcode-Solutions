class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = (int)nums.size();
        if (nums.size() == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        int l = 1, r = n - 2;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid - 1] != nums[mid] and nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            if ((mid % 2 == 1 and nums[mid - 1] == nums[mid]) or
                (mid % 2 == 0 and nums[mid] == nums[mid + 1])) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};