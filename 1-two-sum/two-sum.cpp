class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(),
             [&](const int& a, const int& b) { return nums[a] < nums[b]; });
        int s = 0, e = n - 1, sum;
        while (s < e) {
            sum = nums[indices[s]] + nums[indices[e]];
            if (sum == target) {
                return {indices[s], indices[e]};
            } else if (sum < target) {
                s++;
            } else {
                e--;
            }
        }
        return {};
    }
};
