class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<=1)return n;
        vector<int>nums(n+1);
        nums[0]=0;
        nums[1]=1;
        for(int i=2;i<=n;i++){
            if(i&1){
                int temp = i-1;
                temp/=2;
                nums[i]=nums[temp]+nums[temp+1];
            }
            else{
                nums[i]=nums[i/2];
            }
        }
        int max=-1;
        for(auto i:nums){
            if(max<i){
                max=i;
            }
        }
        return max;
    }
};