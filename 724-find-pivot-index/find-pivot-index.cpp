class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)sum+=i;
        int n=nums.size();
        int lsum=0;
        for(int i=0;i<n;i++){
            if(lsum==sum-lsum-nums[i])return i;
            lsum+=nums[i];
        }
        return -1;
    }
};