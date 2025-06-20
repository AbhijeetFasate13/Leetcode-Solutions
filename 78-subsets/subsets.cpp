class Solution {
    void rec(const int& level, const vector<int>& nums, vector<int>& currSubset,
             vector<vector<int>>& allSubsets) {
        if (level == nums.size()) {
            allSubsets.push_back(currSubset);
            return;
        }
        rec(level + 1, nums, currSubset, allSubsets);
        currSubset.push_back(nums[level]);
        rec(level + 1, nums, currSubset, allSubsets);
        currSubset.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> container;
        rec(0, nums, container, ans);
        return ans;
    }
};