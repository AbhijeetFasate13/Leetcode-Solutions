class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = (int)nums.size();
        unordered_set<int> hash;
        for (const auto& i : nums) {
            hash.insert(i);
        }
        int LCS = 0;
        for (const auto& i : hash) {
            if (hash.find(i - 1) != hash.end()) {
                continue;
            }
            int len = 1;
            while (hash.find(i + len) != hash.end()) {
                len++;
            }
            LCS = max(LCS, len);
        }
        return LCS;
    }
};