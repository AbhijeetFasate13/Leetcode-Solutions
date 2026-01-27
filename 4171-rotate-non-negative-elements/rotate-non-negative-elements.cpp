class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> nonNegNums;
        for (const int& i : nums) {
            if (i >= 0) {
                nonNegNums.push_back(i);
            }
        }
        int n = nonNegNums.size();
        if(n==0)return nums;
        k %= n;
        reverse(nonNegNums.begin(), nonNegNums.begin() + k);
        reverse(nonNegNums.begin() + k, nonNegNums.end());
        reverse(nonNegNums.begin(), nonNegNums.end());
        int ptr = 0;
        for (int& i : nums) {
            if (i >= 0) {
                i = nonNegNums[ptr++];
            }
        }
        return nums;
    }
};