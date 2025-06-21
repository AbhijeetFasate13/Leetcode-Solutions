class Solution {
    void rec(int idx, int n, int target, int sum, const vector<int>& candidates,
             vector<int>& currSet, vector<vector<int>>& solutionSet) {
        if (idx == n) {
            if (sum == target) {
                solutionSet.push_back(currSet);
            }
            return;
        }
        rec(idx + 1, n, target, sum, candidates, currSet, solutionSet);
        if (sum + candidates[idx] <= target) {
            currSet.push_back(candidates[idx]);
            rec(idx, n, target, sum + candidates[idx], candidates, currSet,
                solutionSet);
            currSet.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currSet;
        vector<vector<int>> solutionSet;
        rec(0, candidates.size(), target, 0, candidates, currSet, solutionSet);
        return solutionSet;
    }
};