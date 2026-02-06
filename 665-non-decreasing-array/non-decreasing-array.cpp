class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return true;
        int allowed = 1;
        vector<int> one, two;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] <= nums[i + 1])
                continue;
            if (allowed) {
                one = nums;
                two = nums;
                one[i] = nums[i + 1];
                two[i + 1] = nums[i];
                allowed--;
            } else
                return false;
        }
        return is_sorted(begin(one), end(one)) or
               is_sorted(begin(two), end(two));
    }
};