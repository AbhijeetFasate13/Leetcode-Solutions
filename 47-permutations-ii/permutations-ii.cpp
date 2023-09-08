class Solution {
    void helper(vector<int>container,int i,int n,vector<vector<int>>&ans){
        if(i==n-1){
            ans.push_back(container);
            return;
        }
        for(int j=i;j<n;j++){
            if(j!=i and container[i]==container[j])continue;
            swap(container[i],container[j]);
            helper(container,i+1,n,ans);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<vector<int>>ans;
        helper(nums,0,nums.size(),ans);
        return ans;
    }
};