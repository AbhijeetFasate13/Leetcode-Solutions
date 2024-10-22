class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        map<int, int> mp;
        for (const auto& i : nums) {
            mp[i]++;
        }
        int maxCount = 1;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int count = 1;
            auto it1 = it;
            it1++;
            if (it1 == mp.end()) {
                break;
            }
            while (it->first + 1 == it1->first and it1 != mp.end()) {
                count++;
                it++;
                it1++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};