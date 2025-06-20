class Solution {
    void rec(int level, const vector<int>& nums, vector<int>& currSubset,
             vector<vector<int>>& allSubsets) {
        allSubsets.push_back(currSubset);
        for (int i = level; i < nums.size(); i++) {
            if (i > level and nums[i] == nums[i - 1])
                continue;
            currSubset.push_back(nums[i]);
            rec(i + 1, nums, currSubset, allSubsets);
            currSubset.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        vector<int> container;
        rec(0, nums, container, subsets);
        return subsets;
    }
};
