class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(begin(sortedNums), end(sortedNums));
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = distance(
                sortedNums.begin(),
                lower_bound(begin(sortedNums), end(sortedNums), nums[i]));
        }
        return ans;
    }
};