class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a = {nums[0]}, b = {nums[1]};
        int n = nums.size();
        for (int i = 2; i < n; i++) {
            if (a.back() > b.back()) {
                a.push_back(nums[i]);
            } else {
                b.push_back(nums[i]);
            }
        }
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            if (i < a.size()) {
                result[i] = a[i];
            } else {
                result[i] = b[i - a.size()];
            }
        }
        return result;
    }
};