class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, great;
        int n = (int)nums.size();
        vector<int> ans;
        for (const auto& i : nums) {
            if (i < pivot) {
                less.push_back(i);
            } else if (i > pivot) {
                great.push_back(i);
            } else {
                equal.push_back(i);
            }
        }
        for (const auto& i : less) {
            ans.push_back(i);
        }
        for (const auto& i : equal) {
            ans.push_back(i);
        }
        for (const auto& i : great) {
            ans.push_back(i);
        }
        return ans;
    }
};