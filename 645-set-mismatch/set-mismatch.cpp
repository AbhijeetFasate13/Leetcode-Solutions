class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>hash(n+1);
        for(auto i:nums){
            hash[i]++;
        }
        int repeat,needed=n;
        for(int i=1;i<=n;i++){
            if(hash[i]==0){
                needed=i;
            }
            if(hash[i]==2){
                repeat=i;
            }
        }
        return {repeat,needed};
    }
};