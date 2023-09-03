class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size()-1;i++){
            if(binary_search(begin(nums)+i+1,end(nums),nums[i]))
            {
                return true;
            }
        }
        return false;
    }
};