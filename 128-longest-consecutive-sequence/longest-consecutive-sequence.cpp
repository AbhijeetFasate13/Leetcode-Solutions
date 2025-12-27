class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return n;
        sort(begin(nums),end(nums));
        int len = 1, LCS = 1;
        for (int i=1;i<n;i++) {
            if(nums[i-1]+1==nums[i]){
                len++;
                LCS = max(len,LCS);
            }else if(nums[i-1]==nums[i]){
                continue;
            }else{
                len = 1;
            }
        }
        return LCS;
    }
};