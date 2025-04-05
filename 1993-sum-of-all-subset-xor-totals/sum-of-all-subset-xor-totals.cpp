class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = (int)nums.size();
        int sum = 0;
        for (int i = 0; i < (1 << n); i++) {
            int xori = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    xori ^= nums[j];
                }
            }
            sum += xori;
        }
        return sum;
    }
};