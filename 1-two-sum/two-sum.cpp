class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> given;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            given.push_back({nums[i], i});
        }
        sort(given.begin(), given.end());
        int s = 0, e = n - 1;
        vector<int> ans;
        while (s < e) {
            if (given[s].first + given[e].first > target) {
                e--;
            } else if (given[s].first + given[e].first < target) {
                s++;
            } else {
                ans.push_back(given[s].second);
                ans.push_back(given[e].second);
                break;
            }
        }
        return ans;
    }
};
