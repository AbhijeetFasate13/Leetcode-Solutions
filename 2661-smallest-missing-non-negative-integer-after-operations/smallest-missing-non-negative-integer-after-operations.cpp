class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> rems(value);
        for (const auto& i : nums) {
            rems[(i % value + value) % value]++;
        }
        int mex = 0;
        int it = 0;
        while(rems[it]!=0){
            rems[it++]--;
            mex++;
            it%=value;
        }
        return mex;
    }
};