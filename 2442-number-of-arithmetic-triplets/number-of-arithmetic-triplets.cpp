class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        vector<int>hash(205);
       for(auto i:nums){
           hash[i]++;
       }
       int count=0;
       for(auto i:nums){
           if(i<diff || i+diff>=205)continue;
           if(hash[i-diff] and hash[i+diff])count++;
       }
       return count;
    }
};