class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (const auto& i : nums) {
            hash[i]++;
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end()) {
                ans.push_back({-1 * hash[nums[i]], nums[i]});
                hash.erase(nums[i]);
            }
        }
        sort(ans.begin(), ans.end());
        vector<int> finalAns(k);
        for (int i = 0; i < k; i++) {
            finalAns[i] = ans[i].second;
        }
        return finalAns;
    }
};