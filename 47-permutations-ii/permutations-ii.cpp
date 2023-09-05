class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<vector<int>>ans;
        ans.push_back(nums);
        while(next_permutation(begin(nums),end(nums))){
            ans.push_back(nums);
        }
        return ans;
    }
};