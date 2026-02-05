class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            int shift = nums[i] % n;
            int newIndex = (i + shift + n) % n;
            result[i] = nums[newIndex];
        }

        return result;
    }
};
