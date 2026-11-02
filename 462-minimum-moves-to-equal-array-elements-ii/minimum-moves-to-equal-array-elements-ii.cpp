class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int moves = 0, n = nums.size();
        for (const auto& i : nums) {
            moves += abs(i - nums[n / 2]);
        }
        return moves;
    }
};