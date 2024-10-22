class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = nums[0];
        int n = (int)nums.size();
        for(int i=1;i<n;i++){
            if(maxJump == 0){
                return false;
            }
            maxJump--;
            maxJump = max(maxJump,nums[i]);
        }
        return true;
    }
};