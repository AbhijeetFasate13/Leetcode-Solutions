class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(begin(nums),end(nums));
        int cost = 0;
        for(const auto& i:nums){
            cost += maxi-i;
        }
        return cost;
    }
};