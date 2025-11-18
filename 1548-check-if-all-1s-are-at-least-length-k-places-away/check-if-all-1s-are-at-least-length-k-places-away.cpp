class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int len = 0;
        int n = nums.size();
        bool seenOne = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                len++;
            } else {
                if(!seenOne){
                    seenOne = true;
                    len = 0;
                    continue;
                }
                if (len < k) {
                    return false;
                }
                len = 0;
            }
        }
        return true;
    }
};