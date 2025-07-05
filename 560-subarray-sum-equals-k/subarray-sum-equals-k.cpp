class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int sum = 0;
        int count = 0;
        for (const auto& i : nums) {
            sum += i;
            if (prefixCount.count(sum - k)) {
                count += prefixCount[sum - k];
            }
            prefixCount[sum]++;
        }
        return count;
    }
};