class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int x = 0, y = n;
        vector<int> shuffled(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            shuffled[i] = i % 2 == 0 ? nums[x++] : nums[y++];
        }
        return shuffled;
    }
};