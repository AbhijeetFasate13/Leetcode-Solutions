class Solution {
    void backtrack(const vector<int>& nums, int start, vector<int>& subset,
                   vector<vector<int>>& subsets) {
        if (start == nums.size()) {
            subsets.push_back(subset);
            return;
        }
        subset.push_back(nums[start]);
        backtrack(nums, start + 1, subset, subsets);
        subset.pop_back();
        backtrack(nums, start + 1, subset, subsets);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        backtrack(nums, 0, subset, subsets);
        return subsets;
    }
};