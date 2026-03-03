class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> seen;
        int sum = 0;
        int count = 0;
        seen.insert(0);
        for (int num : nums) {
            sum += num;
            if (seen.count(sum - target)) {
                count++;
                sum = 0;
                seen.clear();
                seen.insert(0);
            } else {
                seen.insert(sum);
            }
        }
        
        return count;
    }
};