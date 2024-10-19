class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        for(int i=0;i<(int)nums.size();i++){
            if(nums[i]){
                nums[ptr++]=nums[i];
            }
        }
        for(int i=ptr;i<(int)nums.size();i++){
            nums[i]=0;
        }
    }
};