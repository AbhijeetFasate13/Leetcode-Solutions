class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=0,mx_m=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx+=nums[i];
            mx_m=max(mx_m,mx);
            if(mx<0)mx=0;
        }
        return mx_m;
    }
};