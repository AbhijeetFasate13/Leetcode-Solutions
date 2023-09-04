class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>hash1(1005),hash2(1005);
        for(auto i:nums1)hash1[i]++;
        for(auto i:nums2)hash2[i]++;
        vector<int>inter;
        for(int i=0;i<1005;i++){
            if(hash1[i]>0 and hash2[i]>0){
                int temp=min(hash1[i],hash2[i]);
                while(temp--){
                    inter.push_back(i);
                }
            }
        }
        return inter;
    }
};