class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        for (const auto& i : nums) {
            long long int curr = i;
            while (!ans.empty() and ans.back() == curr) {
                curr *= 2;
                ans.pop_back();
            }
            ans.push_back(curr);
        }
        return ans;
    }
};