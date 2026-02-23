class Solution {
    void helper(vector<int> container, int i, vector<vector<int>>& ans) {
        if (i == container.size()) {
            ans.push_back(container);
            return;
        }
        for (int j = i; j < container.size(); j++) {
            if (j != i and container[i] == container[j])
                continue;
            swap(container[i], container[j]);
            helper(container, i + 1, ans);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        helper(nums, 0, ans);
        return ans;
    }
};