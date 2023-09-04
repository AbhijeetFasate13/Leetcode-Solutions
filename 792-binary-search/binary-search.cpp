class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while(high>low+1){
            int mid = (low+high)/2;
            if(nums[mid]<=target){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        if(nums[low]==target)
        return low;
        return -1;
    }
};