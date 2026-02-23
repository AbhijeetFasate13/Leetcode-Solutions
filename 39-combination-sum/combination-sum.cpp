class Solution {
    void rec(int idx, int target, const vector<int>& candidates,
             vector<int>& pos, vector<vector<int>>& sol) {
        if (idx == candidates.size()) {
            if (target == 0) {
                sol.push_back(pos);
            }
            return;
        }
        if (target >= candidates[idx]) {
            pos.push_back(candidates[idx]);
            rec(idx, target - candidates[idx], candidates, pos, sol);
            pos.pop_back();
        }
        rec(idx + 1, target, candidates, pos, sol);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int>pos;
        rec(0, target, candidates, pos, sol);
        return sol;
    }
};