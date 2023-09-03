class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        int a = nums[0]*nums[1]*nums[n-1];
        int b = nums[n-1]*nums[n-2]*nums[n-3];
        return a>b?a:b;
    }
};