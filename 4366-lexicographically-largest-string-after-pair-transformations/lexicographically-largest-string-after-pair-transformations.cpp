class Solution {
    unordered_map<int, string> cache;
    int getHighestPower2(int x) { return floor(log2(x)); }
    string largestStringPossible(int x) {
        string ans;
        while (x != 0) {
            int highestPowerOf2 = getHighestPower2(x);
            while (x > 0 and highestPowerOf2 > 25) {
                x -= (1 << 25);
                ans += 'z';
                highestPowerOf2 = getHighestPower2(x);
            }
            ans += highestPowerOf2 + 'a';
            x -= 1 << highestPowerOf2;
        }
        return ans;
    }

public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            if (cache.find(nums[i]) != cache.end()) {
                ans[i] = cache[nums[i]];
                continue;
            }
            ans[i] = largestStringPossible(nums[i]);
            cache[nums[i]] = ans[i];
        }
        return ans;
    }
};