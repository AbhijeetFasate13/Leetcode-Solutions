class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(begin(nums), end(nums));
        while (binary_search(begin(nums), end(nums), original)) {
            original *= 2;
        }
        return original;
    }
};