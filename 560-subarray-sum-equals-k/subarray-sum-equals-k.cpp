class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++){
            nums[i] += nums[i-1];
        }
        map<int,int> mp;
        mp[0]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int req = nums[i] - k;
            ans += mp[nums[i]-k];
            mp[nums[i]]++;
        }
        return ans;
    }
};