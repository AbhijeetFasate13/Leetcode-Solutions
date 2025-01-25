class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int sum = 0;
        for(int i = 0; i < (int)nums.size(); i+=2){
            sum += nums[i];
        }
        return sum;
    }
};