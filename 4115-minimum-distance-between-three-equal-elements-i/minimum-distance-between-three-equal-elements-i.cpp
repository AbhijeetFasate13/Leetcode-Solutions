class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return -1;
        unordered_map<int, vector<int>> mp;
        bool exists = false;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            if (mp[nums[i]].size() > 2)
                exists = true;
        }
        if (!exists)
            return -1;
        int minm = INT_MAX, sz;
        vector<int> curr;
        for (const auto& i : mp) {
            curr = i.second;
            sz = curr.size();
            if (sz < 3)
                continue;
            for (int j = 0; j < sz - 2; j++) {
                minm = min(minm, abs(curr[j] - curr[j + 1]) +
                                     abs(curr[j + 1] - curr[j + 2]) +
                                     abs(curr[j] - curr[j + 2]));
            }
        }
        return minm;
    }
};