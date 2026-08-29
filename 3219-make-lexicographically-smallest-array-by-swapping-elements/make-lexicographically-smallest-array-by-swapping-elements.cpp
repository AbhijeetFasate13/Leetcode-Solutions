class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted = nums;
        sort(begin(sorted),end(sorted));
        vector<vector<int>> groups;
        unordered_map<int, int> map;
        int id = -1;

        for (int i = 0; i < sorted.size(); i++) {
            if (i == 0 || sorted[i] - sorted[i - 1] > limit) {
                groups.push_back({});
                id++;
            }
            groups[id].push_back(sorted[i]);
            map[sorted[i]] = id;
        }

        vector<int> idx(groups.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            int cur = map[nums[i]];
            nums[i] = groups[cur][idx[cur]];
            idx[cur]++;
        }

        return nums;
    }
};