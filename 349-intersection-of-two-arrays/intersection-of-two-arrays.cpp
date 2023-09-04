class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>hash(1005);
        for(auto i:nums1)hash[i]++;
        for(auto i:nums2){
            if(hash[i]>0){
                hash[i]=-1;
            }
        }
        vector<int>intersection;
        for(int i=0;i<1005;i++){
            if(hash[i]==-1){
                intersection.push_back(i);
            }
        }
        return intersection;
    }
};