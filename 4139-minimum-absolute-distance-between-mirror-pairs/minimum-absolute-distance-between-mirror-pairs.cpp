class Solution {
    int reverse(int x) {
        string num = to_string(x);
        std::reverse(begin(num), end(num));
        return stoi(num);
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int minm = INT_MAX, rev;
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i])) {
                minm = min(minm, abs(i - mp[nums[i]]));
            }
            try {
                rev = reverse(nums[i]);
            } catch (...) {
                continue;
            }
            mp[rev] = i;
        }
        return minm == INT_MAX ? -1 : minm;
    }
};