class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int x = 0, y = n;
        vector<int> shuffled;
        for (int i = 0; i < n; i++) {
            shuffled.push_back(nums[x++]);
            shuffled.push_back(nums[y++]);
        }
        return shuffled;
    }
};