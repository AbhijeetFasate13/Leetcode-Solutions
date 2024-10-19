class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == i + 1)
                continue;
            while (nums[i] != i + 1) {
                if (nums[i] == nums[nums[i] - 1]) {
                    ans = nums[i];
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
            }
            if (ans != -1) {
                break;
            }
        }
        return ans;
    }
};