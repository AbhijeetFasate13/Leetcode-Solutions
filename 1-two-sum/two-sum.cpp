class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsToIdx;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int rem = target - nums[i];
            if (numsToIdx.find(rem) != numsToIdx.end()) {
                return {numsToIdx[rem], i};
            }
            numsToIdx[nums[i]] = i;
        }
        return {-1, -1};
    }
};