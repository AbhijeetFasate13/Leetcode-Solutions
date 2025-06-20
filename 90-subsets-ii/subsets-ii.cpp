class Solution {
    void rec(const int &level, const vector<int>& nums, vector<int>& currSubset, set<vector<int>>& allSubsets){
        if(level == nums.size()){
            if(allSubsets.find(currSubset)==allSubsets.end()){
                allSubsets.insert(currSubset);
            }
            return;
        }
        rec(level+1,nums,currSubset,allSubsets);
        currSubset.push_back(nums[level]);
        rec(level+1,nums,currSubset,allSubsets);
        currSubset.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        set<vector<int>>solutionSet;
        vector<int>container;
        rec(0,nums,container,solutionSet);
        vector<vector<int>>subsets;
        for(const auto &i:solutionSet){
            subsets.push_back(i);
        }
        return subsets;
    }
};