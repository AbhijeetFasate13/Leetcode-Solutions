class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd = 0;
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                odd++;
            }
            mp[odd]++;
            if (mp.find(odd - k) != mp.end()) {
                count += mp[odd - k];
            }
        }
        return count;
    }
};