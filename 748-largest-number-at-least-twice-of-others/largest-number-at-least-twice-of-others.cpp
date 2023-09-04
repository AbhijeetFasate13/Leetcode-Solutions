class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max=INT_MIN,max2=INT_MIN+1;
        int max_ind=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max2=max;
                max=nums[i];
                max_ind=i;
            }
            else if(nums[i]>max2 and nums[i]!=max){
                max2=nums[i];
            }
        }
        if(max>=2*max2){
            return max_ind;
        }
        return -1;
    }
};